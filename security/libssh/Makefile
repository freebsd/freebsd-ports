# Created by: Alexander Logvinov <ports@logvinov.com>
# $FreeBSD$

PORTNAME=	libssh
DISTVERSION=	0.5.5
CATEGORIES=	security devel
MASTER_SITES=	https://red.libssh.org/attachments/download/51/ \
		LOCAL/fluffy

MAINTAINER=	fluffy@FreeBSD.org
COMMENT=	Library implementing the SSH1 and SSH2 protocol

OPTIONS_DEFINE=	GCRYPT SSH1
GCRYPT_DESC=	Build with libgcrypt
SSH1_DESC=	Build with SSH1 support

USES=		cmake
CMAKE_SOURCE_PATH=	${WRKSRC}
CONFIGURE_WRKSRC=	${CMAKE_SOURCE_PATH}/build
BUILD_WRKSRC=		${CONFIGURE_WRKSRC}
INSTALL_WRKSRC?=	${BUILD_WRKSRC}
CMAKE_ARGS+=	-DWITH_STATIC_LIB:BOOL=ON
USE_LDCONFIG=	yes

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGCRYPT}
LIB_DEPENDS+=	gcrypt:${PORTSDIR}/security/libgcrypt
CMAKE_ARGS+=	-DWITH_GCRYPT:BOOL=ON
.else
USE_OPENSSL=	yes
.endif

.if ${PORT_OPTIONS:MSSH1}
CMAKE_ARGS+=	-DWITH_SSH1:BOOL=ON
PLIST_SUB+=	SSH1=""
.else
CMAKE_ARGS+=	-DWITH_SSH1:BOOL=OFF
PLIST_SUB+=	SSH1="@comment "
.endif

post-patch:
	@${RM} ${PATCH_WRKSRC}/cmake/Modules/UseDoxygen.cmake
	@${REINPLACE_CMD} -e '/add_subdirectory.*s)/d' \
		-e 's|LIB_INSTALL_DIR}|CMAKE_INSTALL_PREFIX}/libdata|' \
		${PATCH_WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} -e 's|ssh_static|ssh|' \
		${PATCH_WRKSRC}/src/CMakeLists.txt

.include <bsd.port.mk>
