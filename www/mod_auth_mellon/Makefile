# Created by: Ryan Steinmetz <zi@FreeBSD.org>

PORTNAME=	mod_auth_mellon
PORTVERSION=	0.17.0
CATEGORIES=	www
PKGNAMEPREFIX=	${APACHE_PKGNAMEPREFIX}
DISTVERSIONPREFIX=	v

MAINTAINER=	zi@FreeBSD.org
COMMENT=	Apache module with a simple SAML 2.0 service provider

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libcurl.so:ftp/curl \
    		liblasso.so:security/lasso

USES=		apache:2.2+ autoreconf cpe gettext-runtime gnome libtool \
		pkgconfig ssl
USE_GNOME=	glib20
USE_GITHUB=	yes
GH_ACCOUNT=	latchset
CPE_VENDOR=	${GH_ACCOUNT}

GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	OPENSSL_CFLAGS="-I${OPENSSLINC}" OPENSSL_LIBS="-L${OPENSSLLIB} -lcrypto" \
			PKG_CONFIG_PATH="${LOCALBASE}/libdata/pkgconfig"

PLIST_FILES=	${APACHEMODDIR}/mod_auth_mellon.so
SUB_FILES=	pkg-message

post-patch:
	@${REINPLACE_CMD} -e \
		's|@APXS2@ -i|@APXS2@ -S LIBEXECDIR=${STAGEDIR}${PREFIX}/${APACHEMODDIR} -i|' \
		${WRKSRC}/Makefile.in

pre-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${APACHEMODDIR}

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${APACHEMODDIR}/${PORTNAME}.so

.include <bsd.port.mk>
