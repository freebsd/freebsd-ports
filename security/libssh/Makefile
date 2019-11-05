# Created by: Alexander Logvinov <ports@logvinov.com>
# $FreeBSD$

PORTNAME=	libssh
DISTVERSION=	0.8.6
CATEGORIES=	security devel
MASTER_SITES=	https://www.libssh.org/files/0.8/

MAINTAINER=	phascolarctos@protonmail.ch
COMMENT=	Library implementing the SSH2 protocol

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake cpe tar:xz
USE_LDCONFIG=	yes

CMAKE_ARGS=	-DWITH_EXAMPLES:BOOL=OFF \
		-DWITH_TESTING:BOOL=OFF \
		-DWITH_ZLIB:BOOL=ON

OPTIONS_DEFINE=	GSSAPI STATIC
OPTIONS_RADIO=	CRYPTO
OPTIONS_RADIO_CRYPTO=	GCRYPT OPENSSL
OPTIONS_DEFAULT=	GSSAPI OPENSSL STATIC
OPTIONS_SUB=	yes

GCRYPT_LIB_DEPENDS=	libgcrypt.so:security/libgcrypt
GCRYPT_CMAKE_BOOL=	WITH_GCRYPT
GSSAPI_CMAKE_BOOL=	WITH_GSSAPI
OPENSSL_USES=		ssl
STATIC_CMAKE_BOOL=	WITH_STATIC_LIB

post-patch:
	${RM} ${PATCH_WRKSRC}/cmake/Modules/UseDoxygen.cmake
	${REINPLACE_CMD} \
		-e 's|LIB_INSTALL_DIR}|CMAKE_INSTALL_PREFIX}/libdata|' \
		-e 's|CMAKE_INSTALL_DIR}|CMAKE_INSTALL_DIR}/libssh|' \
		${WRKSRC}/CMakeLists.txt
#	${REINPLACE_CMD} -e 's|-lssh_threads|-lssh_threads -lpthread|' \
#		${WRKSRC}/libssh_threads.pc.cmake
	${REINPLACE_CMD} -e 's| -pedantic-errors||' \
		${WRKSRC}/cmake/Modules/DefineCompilerFlags.cmake

.include <bsd.port.mk>
