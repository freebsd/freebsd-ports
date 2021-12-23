PORTNAME=	scs
DISTVERSIONPREFIX=	v
DISTVERSION=	3.0.0
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Solver of convex cone problems via operator splitting

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		gmake blaslapack:openblas fortran # fortran is for openblas
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	cvxgrp

MAKE_ARGS=	BLASLDFLAGS="-lopenblas"

ALL_TARGET=	default

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/*.so

do-test:
	cd ${WRKSRC} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} out/demo_socp_indirect && \
		out/demo_socp_indirect 50 0.3 0.3 50 && \
		${ECHO} "Test succeeded"

.include <bsd.port.mk>
