PORTNAME=	geometric
DISTVERSION=	1.1
PORTREVISION=	2
CATEGORIES=	science python # chemistry
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Geometry optimization for quantum chemistry
WWW=		https://geometric.readthedocs.io/en/latest/ \
		https://github.com/leeping/geomeTRIC

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}networkx>0:math/py-networkx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>0:science/py-scipy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ase>0:science/py-ase@${PY_FLAVOR}

USES=		python shebangfix
USE_PYTHON=	distutils concurrent autoplist pytest # some tests fail because of missing large test files

SHEBANG_GLOB=	*.py

NO_ARCH=	yes

.include <bsd.port.mk>
