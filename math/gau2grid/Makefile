# $FreeBSD$

PORTNAME=	gau2grid
DISTVERSIONPREFIX=	v
DISTVERSION=	2.0.1
CATEGORIES=	math python

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Fast computation of a gaussian and its derivative on a grid

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	amd64
ONLY_FOR_ARCHS_REASON=	BUG: ValueError: descr is not a valid dtype descriptor: '<f16' (see https://github.com/dgasmith/gau2grid/issues/25)

BUILD_DEPENDS=	${PYNUMPY}

USES=		cmake compiler:c11 python:build # C code build depends on python to generate some headers
USE_GITHUB=	yes
GH_ACCOUNT=	dgasmith
USE_LDCONFIG=	yes

.include <bsd.port.mk>
