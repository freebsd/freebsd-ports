# $FreeBSD$

PORTNAME=	claripy
DISTVERSION=	8.20.1.7
PORTREVISION=	1
CATEGORIES=	math devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

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

USES=		python:3.5+
USE_GITHUB=	nodefault
GH_TUPLE=	angr:${PORTNAME}:ea20bb80a84aab942f89cffbf035675dc0cf1af4:tests
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

pre-test:
	@${LN} -Fs ${WRKSRC_tests}/tests ${WRKSRC}/tests

do-test:
	@(cd ${TEST_WRKSRC} && ${SETENV} ${TEST_ENV} nosetests-${PYTHON_VER} tests/*)

.include <bsd.port.mk>
