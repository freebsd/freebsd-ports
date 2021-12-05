PORTNAME=	opensubdiv
DISTVERSIONPREFIX=	v
DISTVERSION=	3_4_4
CATEGORIES=	misc

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Subdivision surface library for digital content creation

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	glfw>0:graphics/glfw \
		opencl>0:devel/opencl
LIB_DEPENDS=	libOpenCL.so:devel/ocl-icd \
		libtbb.so:devel/tbb

USES=		cmake gl xorg
USE_GL=		gl
USE_XORG=	ice

USE_GITHUB=	yes
GH_ACCOUNT=	PixarAnimationStudios
GH_PROJECT=	OpenSubdiv

CMAKE_ON=	NO_EXAMPLES NO_TUTORIALS NO_REGRESSION NO_DOC NO_CUDA NO_TESTS NO_GLTESTS

.include <bsd.port.mk>
