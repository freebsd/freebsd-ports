# Created by: Johannes Dieterich <dieterich@ogolem.org>
# $FreeBSD$

PORTNAME=	clblas
PORTVERSION=	2.10
DISTVERSIONPREFIX=	v
PORTREVISION=	10
CATEGORIES=	math

MAINTAINER=	jmd@FreeBSD.org
COMMENT=	Software library containing BLAS functions written in OpenCL

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	opencl>=0:devel/opencl
LIB_DEPENDS=	libOpenCL.so:devel/ocl-icd \
		libboost_program_options.so:devel/boost-libs
RUN_DEPENDS=	opencl>=0:devel/opencl

USES=		cmake python
USE_LDCONFIG=	yes
USE_CXXSTD=	gnu++98

USE_GITHUB=	yes
GH_ACCOUNT=	clMathLibraries
GH_PROJECT=	clBLAS

CMAKE_ARGS+=	-DBUILD_TEST=OFF \
		-DBUILD_KTEST=OFF \
		-DCORR_TEST_WITH_ACML=OFF \
		-DSUFFIX_LIB=""

CMAKE_SOURCE_PATH=	${WRKSRC}/src

.include <bsd.port.mk>
