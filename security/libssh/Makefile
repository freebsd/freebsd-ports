# Created by: Alexander Logvinov <ports@logvinov.com>
# $FreeBSD$

PORTNAME=	libssh
DISTVERSION=	0.7.3
CATEGORIES=	security devel
MASTER_SITES=	https://git.libssh.org/projects/libssh.git/snapshot/

MAINTAINER=	johans@FreeBSD.org
COMMENT=	Library implementing the SSH1 and SSH2 protocol

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

OPTIONS_DEFINE=	SSH1 STATIC
OPTIONS_RADIO=	CRYPTO
OPTIONS_RADIO_CRYPTO=	GCRYPT OPENSSL
OPTIONS_DEFAULT=	OPENSSL STATIC
OPTIONS_SUB=	yes

USES=		cmake:outsource cpe tar:xz
USE_LDCONFIG=	yes

CMAKE_ARGS=	-DWITH_EXAMPLES:BOOL=OFF \
		-DWITH_GSSAPI:BOOL=ON \
		-DWITH_TESTING:BOOL=OFF \
		-DWITH_ZLIB:BOOL=ON

GCRYPT_LIB_DEPENDS=	libgcrypt.so:security/libgcrypt
GCRYPT_CMAKE_ON=	-DWITH_GCRYPT:BOOL=ON
GCRYPT_CMAKE_OFF=	-DWITH_GCRYPT:BOOL=OFF

OPENSSL_USE=		openssl=yes

SSH1_DESC=		Build with SSH1 support
SSH1_CMAKE_ON=		-DWITH_SSH1:BOOL=ON
SSH1_CMAKE_OFF=		-DWITH_SSH1:BOOL=OFF

STATIC_CMAKE_ON=	-DWITH_STATIC_LIB:BOOL=ON
STATIC_CMAKE_OFF=	-DWITH_STATIC_LIB:BOOL=OFF

post-patch:
	@${RM} ${PATCH_WRKSRC}/cmake/Modules/UseDoxygen.cmake
	@${REINPLACE_CMD} \
		-e 's|LIB_INSTALL_DIR}|CMAKE_INSTALL_PREFIX}/libdata|' \
		-e 's|CMAKE_INSTALL_DIR}|CMAKE_INSTALL_DIR}/libssh|' \
		${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} -e 's|-lssh_threads|-lssh_threads -lpthread|' \
		${WRKSRC}/libssh_threads.pc.cmake
	@${REINPLACE_CMD} -e 's| -pedantic-errors||' \
		${WRKSRC}/cmake/Modules/DefineCompilerFlags.cmake

.include <bsd.port.mk>
