PORTNAME=	cppad
DISTVERSION=	20250000.1
CATEGORIES=	math
PKGNAMEPREFIX=	coin-or-

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ Algorithmic Differentiation package
WWW=		https://coin-or.github.io/CppAD/doc/cppad.htm \
		https://github.com/coin-or/CppAD

LICENSE=	EPL

USES=		cmake compiler:c++11-lang eigen:3,run pkgconfig
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	coin-or
GH_PROJECT=	CppAD

CMAKE_ARGS=	-Dcppad_prefix=${PREFIX}

TEST_TARGET=	check

# tests as of 20250000.1: tests break in the middle, see https://github.com/coin-or/CppAD/issues/222

.include <bsd.port.mk>
