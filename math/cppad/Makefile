# $FreeBSD$

PORTNAME=	cppad
DISTVERSION=	20200000.3
CATEGORIES=	math
PKGNAMEPREFIX=	coin-or-

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ Algorithmic Differentiation package

LICENSE=	EPL

USES=		cmake eigen:3,run
USE_GITHUB=	yes
GH_ACCOUNT=	coin-or
GH_PROJECT=	CppAD
USE_LDCONFIG=	yes

CMAKE_ARGS=	-Dcppad_prefix=${PREFIX}

.include <bsd.port.mk>
