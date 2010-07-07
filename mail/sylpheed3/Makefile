# New ports collection makefile for:	sylpheed
# Date created:                 15 June 2000
# Whom:                         shigeri <shigeri@m10.alpha-net.ne.jp>
#
# $FreeBSD$
#

PORTNAME=	sylpheed
PORTVERSION=	3.0.3
CATEGORIES=	mail ipv6
MASTER_SITES=	http://sylpheed.sraoss.jp/sylpheed/v${PORTVERSION:C/\.[^\.]*$//}/  \
		CRITICAL

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	A lightweight, featureful, and fast GTK+ based e-mail client

RUN_DEPENDS=	${LOCALBASE}/etc/mime.types:${PORTSDIR}/misc/mime-support

USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_ICONV=	yes
USE_GNOME=	gtk20
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

# Sylpheed needs pthread if GnomeVFS is installed (GtkFileChooser uses it)
CONFIGURE_ENV=	CFLAGS="${CFLAGS} ${PTHREAD_CFLAGS}" \
		CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"
CONFIGURE_ARGS=	--enable-ipv6 \
		--prefix=${PREFIX} \
		--with-libintl-prefix=${LOCALBASE} \
		--program-transform-name=''

CONFLICTS=	sylpheed-1.[0-8]* sylpheed-2.[0-9]* sylpheed-gtk2-[0-9]*

OPTIONS=	GPGME		"Enable GnuPG support using GPGME." off \
		COMPFACE	"Enable X-Face support." off \
		JPILOT		"Enable JPilot support." off \
		LDAP		"Enable LDAP support." off \
		SSL		"Enable OpenSSL support." on \
		GTKSPELL	"Enable Spell checking support" on \
		ONIGURUMA	"Enable Oniguruma support" off

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_SSL)
# we can't use USE_OPENSSL=yes after including bsd.port.pre.mk
.include "${PORTSDIR}/Mk/bsd.openssl.mk"
CONFIGURE_ARGS+=--enable-ssl
.else
CONFIGURE_ARGS+=--disable-ssl
.endif

.if defined(WITH_GPGME)
LIB_DEPENDS+=	gpgme.18:${PORTSDIR}/security/gpgme
RUN_DEPENDS+=	gpg:${PORTSDIR}/security/gnupg
CONFIGURE_ARGS+=--enable-gpgme
.else
CONFIGURE_ARGS+=--disable-gpgme
.endif

.if defined(WITH_COMPFACE)
LIB_DEPENDS+=	compface.1:${PORTSDIR}/mail/faces
CONFIGURE_ARGS+=--enable-compface
.else
CONFIGURE_ARGS+=--disable-compface
.endif

.if defined(WITH_JPILOT)
LIB_DEPENDS+=	pisock.9:${PORTSDIR}/palm/pilot-link
RUN_DEPENDS+=	jpilot:${PORTSDIR}/palm/jpilot
CONFIGURE_ARGS+=--enable-jpilot
.else
CONFIGURE_ARGS+=--disable-jpilot
.endif

.if defined(WITH_LDAP)
USE_OPENLDAP=	yes
CONFIGURE_ARGS+=--enable-ldap
.else
CONFIGURE_ARGS+=--disable-ldap
.endif

.if defined(WITH_GTKSPELL)
LIB_DEPENDS+=	gtkspell.0:${PORTSDIR}/textproc/gtkspell
CONFIGURE_ARGS+=--enable-gtkspell
.else
CONFIGURE_ARGS+=--disable-gtkspell
.endif

.if defined(WITH_ONIGURUMA)
BUILD_DEPENDS+=	${LOCALBASE}/lib/libonig.a:${PORTSDIR}/devel/oniguruma5
CONFIGURE_ARGS+=--enable-oniguruma
.else
CONFIGURE_ARGS+=--disable-oniguruma
.endif

MAKEFILES=	Makefile.in ac/Makefile.in faq/Makefile.in faq/de/Makefile.in \
		faq/en/Makefile.in faq/es/Makefile.in faq/fr/Makefile.in \
		faq/it/Makefile.in manual/Makefile.in manual/en/Makefile.in \
		manual/ja/Makefile.in src/Makefile.in libsylph/Makefile.in \
		src/icons/Makefile.in

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS:S/"//g}|g; \
		s|-lresolv||g; s|-lpisock\"|-liconv &|g; \
		s|libs gtkspell-2\.0`|& -laspell|g;' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|/etc|${LOCALBASE}&|g' \
		${WRKSRC}/libsylph/procmime.c

# to prevent breaking cc of ldif.c because of a base64.h in PREFIX/include
	@${REINPLACE_CMD} -e 's|^\(DEFS.*\.\.\)$$|\1 -I../libsylph|' \
		${WRKSRC}/src/Makefile.in

.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e 's|^SUBDIRS = ac libsylph src plugin po manual faq$$|SUBDIRS = ac libsylph src plugin po|g' \
		${WRKSRC}/Makefile.in
.else
.for i in ${MAKEFILES}
	@${REINPLACE_CMD} -e 's|^faqdir = @faqdir@$$|faqdir = ${DOCSDIR}/faq|g; \
		s|^manualdir = @manualdir@$$|manualdir = ${DOCSDIR}/manual|g' \
		${WRKSRC}/${i}
.endfor
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in ChangeLog INSTALL README TODO
	@${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/${i}.ja ${DOCSDIR}
.endfor
.endif
	@${MKDIR} ${PREFIX}/share/pixmaps
	@${MKDIR} ${PREFIX}/share/applications
	@${INSTALL_DATA} ${WRKSRC}/sylpheed.png ${PREFIX}/share/pixmaps/
	@${INSTALL_DATA} ${WRKSRC}/sylpheed.desktop ${PREFIX}/share/applications/

.include <bsd.port.post.mk>
