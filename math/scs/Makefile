# $FreeBSD$

PORTNAME=	scs
DISTVERSION=	2.1.1
PORTREVISION=	3
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Solver of convex cone problems via operator splitting

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		gmake blaslapack:openblas fortran # fortran is for openblas
USE_GITHUB=	yes
GH_ACCOUNT=	cvxgrp
USE_LDCONFIG=	yes

MAKE_ARGS=	BLASLDFLAGS="-lopenblas"

ALL_TARGET=	out/libscsdir.so out/libscsindir.so

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/*.so

.include <bsd.port.mk>
