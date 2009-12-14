# New ports collection makefile for:	libssh
# Date created:				12 April 2009
# Whom:					Alexander Logvinov <ports@logvinov.com>
#
# $FreeBSD$
#

PORTNAME=	libssh
PORTVERSION=	0.4.0
CATEGORIES=	security devel
MASTER_SITES=	http://www.libssh.org/files/ \
		LOCAL/avl

MAINTAINER=	avl@FreeBSD.org
COMMENT=	A library implementing the SSH1 and SSH2 protocol

OPTIONS=	GCRYPT	"Build with libgcrypt"	off

MAKE_JOBS_SAFE=	yes
USE_CMAKE=	yes
CMAKE_SOURCE_PATH=	${WRKSRC}
CONFIGURE_WRKSRC=	${CMAKE_SOURCE_PATH}/build
BUILD_WRKSRC=		${CONFIGURE_WRKSRC}
INSTALL_WRKSRC?=	${BUILD_WRKSRC}
USE_LDCONFIG=	yes

.include <bsd.port.options.mk>

.if defined(WITH_GCRYPT)
LIB_DEPENDS+=	gcrypt.16:${PORTSDIR}/security/libgcrypt
CMAKE_ARGS+=	-DWITH_GCRYPT:BOOL=ON
.else
USE_OPENSSL=	yes
.endif

post-patch:
	@${MKDIR} ${BUILD_WRKSRC}
	@${RM} ${PATCH_WRKSRC}/cmake/Modules/UseDoxygen.cmake
	@${REINPLACE_CMD} -e '/add_subdirectory.*s)/d' \
		${PATCH_WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
