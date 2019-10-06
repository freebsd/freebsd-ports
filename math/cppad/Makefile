# $FreeBSD$

PORTNAME=	cppad
DISTVERSION=	20190200.5
CATEGORIES=	math
PKGNAMEPREFIX=	coin-or-

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ Algorithmic Differentiation package

LICENSE=	EPL

USES=		cmake eigen:3,run
USE_GITHUB=	yes
GH_ACCOUNT=	coin-or
GH_PROJECT=	CppAD

CMAKE_ARGS=	-Dcppad_prefix=${PREFIX}

NO_ARCH=	yes

.include <bsd.port.mk>
