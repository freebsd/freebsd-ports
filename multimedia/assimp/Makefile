# Created by: Yuri <yuri@tsoft.com>
# $FreeBSD$

PORTNAME=	assimp
PORTVERSION=	3.1.1
DISTVERSIONSUFFIX=	_no_test_models
CATEGORIES=	multimedia
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-3.1

MAINTAINER=	yuri@tsoft.com
COMMENT=	Library to import various 3D model formats in a uniform manner

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_powerpc64=	Does not build

WRKSRC=	${WRKDIR}/${PORTNAME}-${PORTVERSION}

USES=		cmake pkgconfig zip
USE_LDCONFIG=	yes

# CMAKE_ARGS instructs cmake to skip runtime path removal during install
CMAKE_ARGS+=	"-DCMAKE_SKIP_RPATH=ON"

OPTIONS_DEFINE=	BOOST
OPTIONS_DEFAULT=	BOOST
BOOST_LIB_DEPENDS=	libboost_filesystem.so:devel/boost-libs
BOOST_CMAKE_ON=	-DASSIMP_ENABLE_BOOST_WORKAROUND:BOOL=OFF

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} < 1000054
# GCC 4.2 causes compiler warnings
USE_GCC=	yes
.endif

post-patch:
	@${REINPLACE_CMD} 's|$${ASSIMP_LIB_INSTALL_DIR}/pkgconfig|libdata/pkgconfig|' \
		${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
