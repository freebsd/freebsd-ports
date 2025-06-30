PORTNAME=	mod_auth_mellon
PORTVERSION=	0.19.1
PORTREVISION=	1
DISTVERSIONPREFIX=	v
CATEGORIES=	www
PKGNAMEPREFIX=	${APACHE_PKGNAMEPREFIX}

MAINTAINER=	zi@FreeBSD.org
COMMENT=	Apache module with a simple SAML 2.0 service provider
WWW=		https://github.com/latchset/mod_auth_mellon

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libcurl.so:ftp/curl \
    		liblasso.so:security/lasso

USES=		apache autoreconf cpe gettext-runtime gnome libtool \
		pkgconfig ssl
USE_GNOME=	glib20
USE_GITHUB=	yes
GH_ACCOUNT=	latchset
CPE_VENDOR=	mod_auth_mellon_project

GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	OPENSSL_CFLAGS="-I${OPENSSLINC}" OPENSSL_LIBS="-L${OPENSSLLIB} -lcrypto" \
			PKG_CONFIG_PATH="${LOCALBASE}/libdata/pkgconfig"

PLIST_FILES=	${APACHEMODDIR}/mod_auth_mellon.so ${DATADIR}/mellon_create_metadata.sh
SUB_FILES=	pkg-message

post-patch:
	@${REINPLACE_CMD} -e \
		's|@APXS2@ -i|@APXS2@ -S LIBEXECDIR=${STAGEDIR}${PREFIX}/${APACHEMODDIR} -i|' \
		${WRKSRC}/Makefile.in

pre-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${APACHEMODDIR} ${STAGEDIR}${DATADIR}

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${APACHEMODDIR}/${PORTNAME}.so
	${INSTALL_SCRIPT} ${WRKSRC}/mellon_create_metadata.sh ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
