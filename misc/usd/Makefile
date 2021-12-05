PORTNAME=	usd
DISTVERSIONPREFIX=	v
DISTVERSION=	21.11
CATEGORIES=	misc

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES=	8fb0221e16920d8c1ec4bd695d83f605be36f8c3.patch:-p1

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Universal Scene Description is a scene description management system

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libtbb.so:devel/tbb

USES=		cmake

USE_GITHUB=	yes
GH_ACCOUNT=	PixarAnimationStudios
GH_PROJECT=	${PORTNAME:tu}

CMAKE_OFF=	PXR_BUILD_TESTS PXR_BUILD_EXAMPLES PXR_BUILD_TUTORIALS PXR_ENABLE_PYTHON_SUPPORT

OPTIONS_DEFINE=		IMAGING TOOLS
OPTIONS_DEFAULT=	TOOLS
OPTIONS_SUB=		yes

IMAGING_DESC=		Build imaging components
IMAGING_CMAKE_BOOL=	PXR_BUILD_IMAGING
IMAGING_CMAKE_ON=	-DPTEX_INCLUDE_DIR=${LOCALBASE}/include
IMAGING_BROKEN=		see https://github.com/PixarAnimationStudios/USD/issues/1706

TOOLS_DESC=		Build commandline tools
TOOLS_CMAKE_BOOL=	PXR_BUILD_USD_TOOLS
TOOLS_LIB_DEPENDS=	libboost_program_options.so:devel/boost-libs

.include <bsd.port.mk>
