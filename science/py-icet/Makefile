PORTNAME=	icet
DISTVERSION=	3.1
CATEGORIES=	science # chemistry, physics
#MASTER_SITES=	PYPI # no tests
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Pythonic approach to alloy cluster expansions
WWW=		https://icet.materialsmodeling.org \
		https://gitlab.com/materials-modeling/icet

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}pybind11>0:devel/py-pybind11@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ase>0:science/py-ase@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numba>0:devel/py-numba@${PY_FLAVOR} \
		${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}pandas>=0.23:math/py-pandas@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>0:science/py-scipy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}spglib>=1.12.0:science/py-spglib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}trainstation>=1.1:science/py-trainstation@${PY_FLAVOR}

USES=		compiler:c++14-lang python
USE_PYTHON=	pep517 autoplist pytest

USE_GITLAB=	yes
GL_ACCOUNT=	materials-modeling
GL_TAGNAME=	3.1

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/_icet.cpython-311.so

# tests fail to run, see https://gitlab.com/materials-modeling/icet/-/issues/623

.include <bsd.port.mk>
