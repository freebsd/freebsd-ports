# Created by: Yuri <yuri@tsoft.com>
# $FreeBSD$

PORTNAME=	assimp
PORTVERSION=	3.3.1
DISTVERSIONPREFIX=	v
CATEGORIES=	multimedia

MAINTAINER=	yuri@rawbw.com
COMMENT=	Library to import various 3D model formats in a uniform manner

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_aarch64=		Does not compile: error: non-constant-expression cannot be narrowed from type int8_t to char
BROKEN_armv6=		Does not compile: error: non-constant-expression cannot be narrowed from type int8_t to char
BROKEN_powerpc64=	Does not build
BROKEN_armv6=		Does not compile: error: ByteSwap has not been declared

USES=		cmake compiler:c++11-lib pkgconfig
USE_GITHUB=		yes
USE_LDCONFIG=	yes

# CMAKE_ARGS instructs cmake to skip runtime path removal during install
CMAKE_ARGS+=	-DCMAKE_SKIP_RPATH:BOOL=ON -DASSIMP_BUILD_TESTS:BOOL=OFF

.include <bsd.port.pre.mk>

.if ${CHOSEN_COMPILER_TYPE} == gcc
# GCC C++11 support is broken on FreeBSD (see PR 193528 for details)
CXXFLAGS+=	-D_GLIBCXX_USE_C99
.endif

post-patch: .SILENT
	${REINPLACE_CMD} -e '/zzip-zlib-config/d' \
		${WRKSRC}/cmake-modules/FindZLIB.cmake
	${REINPLACE_CMD} -e '/working branch$$/,/^)/d ; /minizip/d ; \
		s|$${ASSIMP_LIB_INSTALL_DIR}/pkgconfig|libdata/pkgconfig|' \
		${WRKSRC}/CMakeLists.txt

.include <bsd.port.post.mk>
