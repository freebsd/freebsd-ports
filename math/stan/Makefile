PORTNAME=	stan
DISTVERSIONPREFIX=	v
DISTVERSION=	2.34.1
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ package for Bayesian inference, maximum likelihood estimation, etc
WWW=		https://mc-stan.org/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	stanmath>0:math/stanmath
TEST_DEPENDS=	gmake:devel/gmake

USES=		eigen:3,run gmake python:test shebangfix

USE_GITHUB=	yes
GH_ACCOUNT=	stan-dev
GH_TUPLE=	stan-dev:math:c26bd83:stan_math/lib/stan_math

SHEBANG_FILES=	runTests.py

MAKE_ENV=	CXX_TYPE=clang

NO_BUILD=	yes
NO_ARCH=	yes

do-install:
	@cd ${WRKSRC}/src && ${COPYTREE_SHARE} stan ${STAGEDIR}${PREFIX}/include

# tests attempt to download some executable
#do-test:
#	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ./runTests.py src/test/unit

.include <bsd.port.mk>
