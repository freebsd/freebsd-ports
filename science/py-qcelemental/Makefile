PORTNAME=	qcelemental
DISTVERSION=	0.51.2
CATEGORIES=	science python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Essentials for quantum chemistry
WWW=		https://github.com/MolSSI/QCElemental

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=61.0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>=8.0:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=2.3.3:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pint>=0.24:devel/py-pint@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydantic2>=2.11:devel/py-pydantic2@${PY_FLAVOR}
ALIGN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}networkx>0:math/py-networkx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>=1.9.0:science/py-scipy@${PY_FLAVOR}
STANDARD_DEPENDS=	\
		${PYTHON_PKGNAMEPREFIX}jsonschema>0:devel/py-jsonschema@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}msgpack>0:devel/py-msgpack@${PY_FLAVOR}
VIZ_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ipykernel>0:devel/py-ipykernel@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}nglview>=3.0.3:science/py-nglview@${PY_FLAVOR}
RUN_DEPENDS+=	${ALIGN_DEPENDS} \
		${STANDARD_DEPENDS} \
		${VIZ_DEPENDS}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>=4.0.0:devel/py-pytest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-cov>0:devel/py-pytest-cov@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}py3Dmol>0:science/py-py3Dmol@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_ARGS=	--disable-plugin-autoload

NO_ARCH=	yes

do-test:
	@cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest -rs --pyargs qcelemental

# tests as of 0.51.2:
# Results (44.04s):
#       6772 passed
#        132 skipped
#          2 xpassed
#         18 warnings

.include <bsd.port.mk>
