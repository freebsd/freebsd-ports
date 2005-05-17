# New ports collection makefile for:	sylpheed
# Date created:                 15 June 2000
# Whom:                         shigeri <shigeri@m10.alpha-net.ne.jp>
#
# $FreeBSD$
#

PORTNAME=	sylpheed
PORTVERSION=	1.9.11
PORTREVISION=	0
CATEGORIES=	mail ipv6
MASTER_SITES=	http://sylpheed.good-day.net/sylpheed/v1.9/ \
		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	sylpheed-claws/

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	A lightweight, featureful, and fast GTK+ based e-mail client

RUN_DEPENDS=	${LOCALBASE}/etc/mime.types:${PORTSDIR}/misc/mime-support

USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_ICONV=	yes
USE_X_PREFIX=	yes
USE_GNOME=	gtk20
USE_LIBTOOL_VER=15
USE_REINPLACE=	yes
NO_LATEST_LINK=	yes

CONFIGURE_ENV=	CPPFLAGS="-I${PREFIX}/include -I${LOCALBASE}/include -I${X11BASE}/include" \
		LIBS="-L${PREFIX}/lib -L${LOCALBASE}/lib -L${X11BASE}/lib"
CONFIGURE_ARGS=	--enable-ipv6 \
		--prefix=${PREFIX} \
		--with-libintl-prefix=${LOCALBASE} \
		--program-transform-name=''

CONFLICTS=	sylpheed-1.[0-8]* sylpheed-gtk2-[0-9]*

OPTIONS=	GPGME		"Enable GnuPG support using GPGME." off \
		COMPFACE	"Enable X-Face support." off \
		JPILOT		"Enable JPilot support." off \
		LDAP		"Enable LDAP support." off \
		SSL		"Enable OpenSSL support." on

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_SSL)
# we can't use USE_OPENSSL=yes after including bsd.port.pre.mk
.include "${PORTSDIR}/Mk/bsd.openssl.mk"
CONFIGURE_ARGS+=--enable-ssl
.endif

.if defined(WITH_GPGME)
LIB_DEPENDS+=	gpgme.14:${PORTSDIR}/security/gpgme
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
LIB_DEPENDS+=	pisock.8:${PORTSDIR}/palm/pilot-link
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
.if !defined(WITHOUT_SSL)
CONFIGURE_ARGS+=--enable-ssl
.else
CONFIGURE_ARGS+=--disable-ssl
.endif

MAKEFILES=	Makefile.in ac/Makefile.in faq/Makefile.in faq/de/Makefile.in \
		faq/en/Makefile.in faq/es/Makefile.in faq/fr/Makefile.in \
		faq/it/Makefile.in manual/Makefile.in manual/en/Makefile.in \
		manual/ja/Makefile.in src/Makefile.in

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS:S/"//g}|g; \
		s|-lresolv||g; s|-lpisock\"|-liconv &|g; ' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|/etc|${LOCALBASE}&|g' \
		${WRKSRC}/src/procmime.c

.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e 's|^SUBDIRS = ac po intl src manual faq$$|SUBDIRS = ac po intl src|g' \
		${WRKSRC}/Makefile.in
.else
.for i in ${MAKEFILES}
	@${REINPLACE_CMD} -e 's|^faqdir = @faqdir@$$|faqdir = ${DOCSDIR}/faq|g; \
		s|^manualdir = @manualdir@$$|manualdir = ${DOCSDIR}/manual|g' \
		${WRKSRC}/${i}
.endfor
.endif

pre-build:
	${LN} -sf ${LIBTOOL} ${WRKSRC}/libtool

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in ChangeLog INSTALL README TODO
	@${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/${i}.ja ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
