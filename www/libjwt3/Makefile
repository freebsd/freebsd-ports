PORTNAME=	libjwt
PORTVERSION=	3.3.3
CATEGORIES=	www
MASTER_SITES=	https://github.com/benmcollins/libjwt/releases/download/v${PORTVERSION}/
PKGNAMESUFFIX=	3

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	JSON Web Token implementation in C
WWW=		https://libjwt.io/ \
		https://github.com/benmcollins/libjwt

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	bash>=0:shells/bash
LIB_DEPENDS=	libjansson.so:devel/jansson

USES=		cmake pkgconfig ssl tar:xz

CMAKE_OFF=	CODE_COVERAGE_VERBOSE \
		ENABLE_COVERAGE \
		WITH_JSON_C \
		WITH_KCAPI_MD \
		WITH_MBEDTLS \
		WITH_TESTS
CMAKE_ON=	EXCLUDE_DEPRECATED
USE_LDCONFIG=	yes

DOCSDIR=	${PREFIX}/share/doc/LibJWT

CONFLICTS_INSTALL=	libjwt

OPTIONS_DEFINE=	CURL DOCS GNUTLS
CURL_DESC=	Retrieve JWKS via cURL

CURL_CMAKE_BOOL=	WITH_LIBCURL
CURL_LIB_DEPENDS=	libcurl.so:ftp/curl
GNUTLS_CMAKE_BOOL=	WITH_GNUTLS
GNUTLS_LIB_DEPENDS=	libgnutls.so:security/gnutls

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' ${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
