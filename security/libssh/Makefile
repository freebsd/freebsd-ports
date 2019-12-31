# Created by: Alexander Logvinov <ports@logvinov.com>
# $FreeBSD$

PORTNAME=	libssh
DISTVERSION=	0.9.3
CATEGORIES=	security devel
MASTER_SITES=	https://www.libssh.org/files/0.9/

MAINTAINER=	salvadore@FreeBSD.org
COMMENT=	Library implementing the SSH2 protocol

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake cpe tar:xz
USE_LDCONFIG=	yes

CMAKE_OFF=	WITH_EXAMPLES

OPTIONS_DEFINE=	GSSAPI STATIC ZLIB
OPTIONS_RADIO=	CRYPTO
OPTIONS_RADIO_CRYPTO=	GCRYPT OPENSSL
OPTIONS_DEFAULT=	GSSAPI OPENSSL STATIC ZLIB
OPTIONS_SUB=	yes

GCRYPT_LIB_DEPENDS=	libgcrypt.so:security/libgcrypt \
			libgpg-error.so:security/libgpg-error
GCRYPT_CMAKE_BOOL=	WITH_GCRYPT
GSSAPI_CMAKE_BOOL=	WITH_GSSAPI
OPENSSL_USES=		ssl
STATIC_CMAKE_BOOL=	BUILD_STATIC_LIB
ZLIB_CMAKE_BOOL=	WITH_ZLIB

post-patch:
	${RM} ${PATCH_WRKSRC}/cmake/Modules/UseDoxygen.cmake
	${REINPLACE_CMD} \
		-e 's|LIB_INSTALL_DIR}|CMAKE_INSTALL_PREFIX}/libdata|' \
		-e 's|CMAKE_INSTALL_DIR}|CMAKE_INSTALL_DIR}/libssh|' \
		${WRKSRC}/CMakeLists.txt

post-install-STATIC-on:
	${INSTALL_DATA} ${CONFIGURE_WRKSRC}/src/libssh.a ${STAGEDIR}${PREFIX}/lib/

.include <bsd.port.mk>
