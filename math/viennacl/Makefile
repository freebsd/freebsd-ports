PORTNAME=	viennacl
PORTVERSION=	1.7.1
PORTREVISION=	6
CATEGORIES=	math
MASTER_SITES=	SF/${PORTNAME}/1.7.x/
DISTNAME=	ViennaCL-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Linear algebra and solver library using CUDA, OpenCL, and OpenMP

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/include/CL/opencl.h:devel/opencl
LIB_DEPENDS=	libOpenCL.so:devel/ocl-icd
RUN_DEPENDS=	${LOCALBASE}/include/CL/opencl.h:devel/opencl

USES=		cmake localbase

.include <bsd.port.mk>
