PORTNAME=	claripy
DISTVERSIONPREFIX=	v
DISTVERSION=	${ANGR_VERSION}
CATEGORIES=	math devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Abstraction layer for constraint solvers

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cachetools>0:devel/py-cachetools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}decorator>0:devel/py-decorator@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}future>0:devel/py-future@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pysmt>0:math/py-pysmt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}z3-solver>4.8.5.0:math/py-z3-solver@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}nose>0:devel/py-nose@${PY_FLAVOR} \
		z3>4.8.5.0:math/z3

USES=		python:3.6+
USE_GITHUB=	yes
GH_ACCOUNT=	angr
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

do-test:
	@(cd ${TEST_WRKSRC} && ${SETENV} ${TEST_ENV} nosetests-${PYTHON_VER} tests/*)

.include "${.CURDIR}/../../security/py-angr/Makefile.version"
.include <bsd.port.mk>
