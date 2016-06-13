# Created by: Yuri <yuri@tsoft.com>
# $FreeBSD$

PORTNAME=	assimp
PORTVERSION=	3.2
DISTVERSIONPREFIX=	v
CATEGORIES=	multimedia

MAINTAINER=	yuri@rawbw.com
COMMENT=	Library to import various 3D model formats in a uniform manner

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_powerpc64=	Does not build

USES=		cmake pkgconfig
USE_GITHUB=		yes
USE_LDCONFIG=	yes

# CMAKE_ARGS instructs cmake to skip runtime path removal during install
CMAKE_ARGS+=	-DCMAKE_SKIP_RPATH:BOOL=ON -DASSIMP_BUILD_TESTS:BOOL=OFF

OPTIONS_DEFINE=	BOOST
OPTIONS_DEFAULT=	BOOST
BOOST_LIB_DEPENDS=	libboost_filesystem.so:devel/boost-libs
BOOST_CMAKE_ON=	-DASSIMP_ENABLE_BOOST_WORKAROUND:BOOL=OFF

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} < 1000054
# GCC 4.2 causes compiler warnings
USE_GCC=	yes
.endif

post-patch: .SILENT
	${REINPLACE_CMD} -e '/zzip-zlib-config/d' \
		${WRKSRC}/cmake-modules/FindZLIB.cmake
	${REINPLACE_CMD} -e '/working branch$$/,/^)/d ; /minizip/d ; \
		s|$${ASSIMP_LIB_INSTALL_DIR}/pkgconfig|libdata/pkgconfig|' \
		${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
