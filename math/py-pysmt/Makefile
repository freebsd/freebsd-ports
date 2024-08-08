PORTNAME=	pysmt
DISTVERSIONPREFIX=	v
DISTVERSION=	0.9.6
CATEGORIES=	math python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Solver-agnostic library for SMT formulae manipulation and solving
WWW=		http://www.pysmt.org

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}six>=0:devel/py-six@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}z3-solver>0:math/py-z3-solver@${PY_FLAVOR} \
		z3>0:math/z3 \
		cvc5>0:math/cvc5

USES=		python
USE_GITHUB=	yes
USE_PYTHON=	distutils autoplist concurrent distutils pytest
PYDISTUTILS_PKGNAME=	PySMT

NO_ARCH=	yes

.include <bsd.port.mk>
