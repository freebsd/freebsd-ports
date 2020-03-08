# $FreeBSD$

PORTNAME=	libxsmm
DISTVERSION=	1.10
PORTREVISION=	6
CATEGORIES=	math science

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library for dense and sparse matrix operations and deep learning

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.md

ONLY_FOR_ARCHS=		amd64
ONLY_FOR_ARCHS_REASON=	relies on hard-coded x86 code, and is only supported on 64-bit

BUILD_DEPENDS=	bash:shells/bash

USES=		fortran gmake localbase:ldflags python:build shebangfix
SHEBANG_GLOB=	*.sh
USE_GITHUB=	yes
GH_ACCOUNT=	hfp
USE_LDCONFIG=	yes

MAKE_ARGS=	STATIC=0 DEPSTATIC=0 MAKE_PARALLEL=1
LDFLAGS+=	-lm

BINARY_ALIAS=	python=${PYTHON_CMD}

.include <bsd.port.mk>
