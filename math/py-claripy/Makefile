PORTNAME=	claripy
DISTVERSIONPREFIX=	v
DISTVERSION=	${ANGR_VERSION}
CATEGORIES=	math devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Abstraction layer for constraint solvers

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cachetools>0:devel/py-cachetools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}decorator>0:devel/py-decorator@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}future>0:devel/py-future@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pysmt>0:math/py-pysmt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}z3-solver>4.8.5.0:math/py-z3-solver@${PY_FLAVOR}
TEST_DEPENDS=	z3>4.8.5.0:math/z3

USES=		angr:nose python:3.6+
USE_GITHUB=	yes
GH_ACCOUNT=	angr
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

.include <bsd.port.mk>
