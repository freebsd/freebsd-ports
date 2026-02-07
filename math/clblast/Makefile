PORTNAME=	clblast
PORTVERSION=	1.6.3
CATEGORIES=	math

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Modern, lightweight, performant and tunable OpenCL BLAS library
WWW=		https://github.com/CNugteren/CLBlast

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	opencl>=0:devel/opencl
LIB_DEPENDS=	libOpenCL.so:devel/ocl-icd
RUN_DEPENDS=	opencl>=0:devel/opencl

USE_GITHUB=	yes
GH_ACCOUNT=	CNugteren
GH_PROJECT=	CLBlast

USES=		cmake
USE_LDCONFIG=	yes
PLIST_SUB=	VER=${PORTVERSION}

OPTIONS_DEFINE=		TEST
OPTIONS_SUB=		yes
TEST_CMAKE_BOOL=	TESTS
TEST_LIB_DEPENDS=	libcblas.so:math/cblas	\
			libclBLAS.so:math/clblas

.include <bsd.port.mk>
