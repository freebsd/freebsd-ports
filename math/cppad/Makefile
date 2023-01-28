PORTNAME=	cppad
DISTVERSION=	20230000.0
CATEGORIES=	math
PKGNAMEPREFIX=	coin-or-

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ Algorithmic Differentiation package
WWW=		https://coin-or.github.io/CppAD/doc/cppad.htm

LICENSE=	EPL

USES=		cmake compiler:c++11-lang eigen:3,run
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	coin-or
GH_PROJECT=	CppAD

CMAKE_ARGS=	-Dcppad_prefix=${PREFIX}

TEST_TARGET=	check

.include <bsd.port.mk>
