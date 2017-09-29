# Created by: Pedro Giffuni <pfg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	viennacl
PORTVERSION=	1.7.1
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	SF/${PORTNAME}/1.7.x/
DISTNAME=	ViennaCL-${PORTVERSION}

MAINTAINER=	pfg@FreeBSD.org
COMMENT=	Linear algebra and solver library using CUDA, OpenCL, and OpenMP

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/include/CL/opencl.h:devel/opencl
LIB_DEPENDS=	libOpenCL.so:devel/ocl-icd
RUN_DEPENDS=	${LOCALBASE}/include/CL/opencl.h:devel/opencl

USES=		cmake:outsource compiler:openmp localbase

.include <bsd.port.mk>
