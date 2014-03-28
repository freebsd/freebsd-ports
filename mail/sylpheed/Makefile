# Created by: shigeri <shigeri@m10.alpha-net.ne.jp>
# $FreeBSD$

PORTNAME=	sylpheed
PORTVERSION=	3.3.1
CATEGORIES=	mail ipv6
MASTER_SITES=	http://sylpheed.sraoss.jp/sylpheed/v${PORTVERSION:C/\.[^\.]*$//}/  \
		CRITICAL

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Lightweight, featureful, and fast GTK+ based e-mail client

LICENSE=	GPLv2 LGPL21
LICENSE_COMB=	dual

RUN_DEPENDS=	${LOCALBASE}/etc/mime.types:${PORTSDIR}/misc/mime-support

USES=		gettext iconv gmake pkgconfig tar:bzip2
USE_GNOME=	gtk20
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

# Sylpheed needs pthread if GnomeVFS is installed (GtkFileChooser uses it)
CONFIGURE_ENV=	LIBS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"
CPPFLAGS+=	-I${LOCALBASE}/include
CFLAGS+=	${PTHREAD_CFLAGS}
CONFIGURE_ARGS=	--enable-ipv6 \
		--prefix=${PREFIX} \
		--with-libintl-prefix=${LOCALBASE} \
		--program-transform-name=''

CONFLICTS=	sylpheed-1.[0-8]* sylpheed-2.[0-9]* sylpheed-gtk2-[0-9]*

OPTIONS_DEFINE=	GPGME COMPFACE JPILOT LDAP SSL GTKSPELL ONIGURUMA DOCS

GPGME_DESC=	GnuPG support using GPGME
COMPFACE_DESC=	X-Face support
JPILOT_DESC=	JPilot support
GTKSPELL_DESC=	Spell checking support
ONIGURUMA_DESC=	Oniguruma support

OPTIONS_DEFAULT=SSL GTKSPELL

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSSL}
USE_OPENSSL=	yes
CONFIGURE_ARGS+=--enable-ssl
.else
CONFIGURE_ARGS+=--disable-ssl
.endif

.if ${PORT_OPTIONS:MGPGME}
LIB_DEPENDS+=	libgpgme.so:${PORTSDIR}/security/gpgme
RUN_DEPENDS+=	gpg:${PORTSDIR}/security/gnupg
CONFIGURE_ARGS+=--enable-gpgme
.else
CONFIGURE_ARGS+=--disable-gpgme
.endif

.if ${PORT_OPTIONS:MCOMPFACE}
LIB_DEPENDS+=	libcompface.so:${PORTSDIR}/mail/faces
CONFIGURE_ARGS+=--enable-compface
.else
CONFIGURE_ARGS+=--disable-compface
.endif

.if ${PORT_OPTIONS:MJPILOT}
LIB_DEPENDS+=	libpisock.so:${PORTSDIR}/palm/pilot-link
RUN_DEPENDS+=	jpilot:${PORTSDIR}/palm/jpilot
CONFIGURE_ARGS+=--enable-jpilot
.else
CONFIGURE_ARGS+=--disable-jpilot
.endif

.if ${PORT_OPTIONS:MLDAP}
USE_OPENLDAP=	yes
CONFIGURE_ARGS+=--enable-ldap
.else
CONFIGURE_ARGS+=--disable-ldap
.endif

.if ${PORT_OPTIONS:MGTKSPELL}
LIB_DEPENDS+=	libgtkspell.so:${PORTSDIR}/textproc/gtkspell
CONFIGURE_ARGS+=--enable-gtkspell
.else
CONFIGURE_ARGS+=--disable-gtkspell
.endif

.if ${PORT_OPTIONS:MONIGURUMA}
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
		s|-lresolv||g; s|-lpisock\"|${ICONV_LIB} &|g;' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|/etc|${LOCALBASE}&|g' \
		${WRKSRC}/libsylph/procmime.c

# to prevent breaking cc of ldif.c because of a base64.h in PREFIX/include
	@${REINPLACE_CMD} -e 's|^\(DEFS.*\.\.\)$$|\1 -I../libsylph|' \
		${WRKSRC}/src/Makefile.in

.if empty(PORT_OPTIONS:MDOCS)
	@${REINPLACE_CMD} -e 's|^SUBDIRS = ac libsylph src plugin po manual faq nsis$$|SUBDIRS = ac libsylph src plugin po nsis|g' \
		${WRKSRC}/Makefile.in
.else
.for i in ${MAKEFILES}
	@${REINPLACE_CMD} -e 's|^faqdir = @faqdir@$$|faqdir = ${DOCSDIR}/faq|g; \
		s|^manualdir = @manualdir@$$|manualdir = ${DOCSDIR}/manual|g' \
		${WRKSRC}/${i}
.endfor
.endif

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ChangeLog INSTALL README TODO
	@${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/${i}.ja ${STAGEDIR}${DOCSDIR}
.endfor
	@${INSTALL_DATA} ${WRKSRC}/sylpheed.png ${STAGEDIR}${PREFIX}/share/pixmaps/
	@${INSTALL_DATA} ${WRKSRC}/sylpheed.desktop ${STAGEDIR}${PREFIX}/share/applications/

.include <bsd.port.mk>
