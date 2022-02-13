PORTNAME=	cppad
DISTVERSION=	20220000.2
CATEGORIES=	math
PKGNAMEPREFIX=	coin-or-

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ Algorithmic Differentiation package

LICENSE=	EPL

USES=		cmake compiler:c++11-lang eigen:3,run
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	coin-or
GH_PROJECT=	CppAD

CMAKE_ARGS=	-Dcppad_prefix=${PREFIX}

.include <bsd.port.mk>
