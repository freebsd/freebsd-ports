# $FreeBSD$

PORTNAME=	pysmt
DISTVERSIONPREFIX=	v
DISTVERSION=	0.8.0
CATEGORIES=	math python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Solver-agnostic library for SMT formulae manipulation and solving

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}six>=0:devel/py-six@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}nose>0:devel/py-nose@${PY_FLAVOR}

# Supported Python versions: 2.7,3.5+
USES=		python
USE_GITHUB=	yes
USE_PYTHON=	autoplist concurrent distutils
PYDISTUTILS_PKGNAME=	PySMT

NO_ARCH=	yes

do-test:
	@(cd ${TEST_WRKSRC} && ${SETENV} ${TEST_ENV} nosetests-${PYTHON_VER} -v)

.include <bsd.port.mk>
