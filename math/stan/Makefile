PORTNAME=	stan
DISTVERSIONPREFIX=	v
DISTVERSION=	2.30.0
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ package for Bayesian inference, maximum likelihood estimation, etc

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	stanmath>0:math/stanmath
TEST_DEPENDS=	gmake:devel/gmake

USES=		eigen:3,run gmake python:test shebangfix

USE_GITHUB=	yes
GH_ACCOUNT=	stan-dev

SHEBANG_FILES=	runTests.py

NO_BUILD=	yes
NO_ARCH=	yes

do-install:
	@cd ${WRKSRC}/src && ${COPYTREE_SHARE} stan ${STAGEDIR}${PREFIX}/include

do-test: # fails to compile: https://github.com/stan-dev/stan/issues/3058
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ./runTests.py src/test/unit

.include <bsd.port.mk>
