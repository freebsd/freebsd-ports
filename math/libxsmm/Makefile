# $FreeBSD$

PORTNAME=	libxsmm
DISTVERSION=	1.10
PORTREVISION=	1
CATEGORIES=	math science

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library for dense and sparse matrix operations and deep learning

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BROKEN_i386=	LIBXSMM is only supported on a 64-bit platform!

BUILD_DEPENDS=	bash:shells/bash
LIB_DEPENDS=	libomp.so:devel/openmp

USES=		fortran gmake localbase:ldflags python:build shebangfix
SHEBANG_GLOB=	*.sh
USE_GITHUB=	yes
GH_ACCOUNT=	hfp
USE_LDCONFIG=	yes

MAKE_ARGS=	STATIC=0 DEPSTATIC=0 MAKE_PARALLEL=1
LDFLAGS+=	-lm

BINARY_ALIAS=	python=${PYTHON_CMD}

.include <bsd.port.mk>
