# Created by: Johannes Dieterich <dieterich@ogolem.org>
# $FreeBSD$

PORTNAME=	clfft
PORTVERSION=	2.6.1
DISTVERSIONPREFIX=	v
CATEGORIES=	math

MAINTAINER=	dieterich@ogolem.org
COMMENT=	Software library containing FFT functions written in OpenCL

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	opencl>=0:${PORTSDIR}/devel/opencl
LIB_DEPENDS=	libOpenCL.so:${PORTSDIR}/devel/ocl-icd
RUN_DEPENDS=	opencl>=0:${PORTSDIR}/devel/opencl

BROKEN_FreeBSD_9=	clFFT is only supported on FreeBSD 10.1 and newer

USE_GITHUB=	yes
GH_ACCOUNT=	clMathLibraries
GH_PROJECT=	clFFT

USE_LDCONFIG=	yes
USES=		cmake

CMAKE_ARGS+=	-DBUILD_CLIENT=OFF \
		-DBUILD_TEST=OFF \
		-DSUFFIX_LIB=""

CMAKE_SOURCE_PATH=	${WRKSRC}/src

.include <bsd.port.mk>
