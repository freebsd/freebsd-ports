PORTNAME=	libxsmm
DISTVERSION=	1.16.3
CATEGORIES=	math science

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library for dense and sparse matrix operations and deep learning

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BROKEN_i386=	error: assigning to '__m256i' (vector of 4 'long long' values) from incompatible type 'int'

BUILD_DEPENDS=	bash:shells/bash

USES=		cpe fortran gmake localbase:ldflags python:build shebangfix
CPE_VENDOR=	${PORTNAME}_project
SHEBANG_GLOB=	*.sh
USE_GITHUB=	yes
GH_ACCOUNT=	hfp
USE_LDCONFIG=	yes

MAKE_ARGS=	STATIC=0 DEPSTATIC=0 MAKE_PARALLEL=1
LDFLAGS+=	-lm

TEST_TARGET=	tests

BINARY_ALIAS=	python=${PYTHON_CMD}

.include <bsd.port.options.mk>

.if ${ARCH} != amd64
MAKE_ARGS+=	PLATFORM=1
.endif

post-install: # https://github.com/hfp/libxsmm/issues/413
	${RMDIR} ${STAGEDIR}${PREFIX}/share/modules

.include <bsd.port.mk>
