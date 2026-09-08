PORTNAME=	optuna
DISTVERSION=	5.0.0
CATEGORIES=	misc # machine-learning
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Hyperparameter optimization framework
WWW=		https://optuna.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
			${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}alembic>=1.5.0:databases/py-alembic@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}colorlog>0:devel/py-colorlog@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}numpy>0:math/py-numpy@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}packaging>=20.0:devel/py-packaging@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}pyyaml>0:devel/py-pyyaml@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}sqlalchemy20>=1.4.2:databases/py-sqlalchemy20@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}tqdm>0:misc/py-tqdm@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}boto3>0:www/py-boto3@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}cmaes>=0.12.0:math/py-cmaes@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}coverage>=0:devel/py-coverage@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}fakeredis>=0:databases/py-fakeredis@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}google-cloud-storage>0:www/py-google-cloud-storage@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}greenlet>0:devel/py-greenlet@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}grpcio>0:devel/py-grpcio@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}matplotlib>0:math/py-matplotlib@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}moto>=0:devel/py-moto@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}pandas>0:math/py-pandas@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}plotly>=4.9.0:graphics/py-plotly@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}protobuf>=5.28.1:devel/py-protobuf@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}pytest-xdist>0:devel/py-pytest-xdist@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}pytorch>0:misc/py-pytorch@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}redis>0:databases/py-redis@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}scikit-learn>=0.24.2:science/py-scikit-learn@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}scipy>=1.9.2:science/py-scipy@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 concurrent autoplist pytest

NO_ARCH=	yes

TEST_ENV=	${MAKE_ENV} \
		PATH=${STAGEDIR}${PREFIX}/bin:${PATH} \
		PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR} \
		MPLBACKEND=Agg \
		PYTEST_ADDOPTS="-p no:black -p no:ruff -p no:mypy -p no:flake8 -p no:cov -p no:benchmark -p no:inline-snapshot -p no:xdist"

PYTEST_IGNORED_TESTS=	test_experimental_class_decorator

# tests as of 5.0.0: 4940 passed, 44 skipped, 2 deselected, 221 warnings in 2259.89s (0:37:39)
# (tests also depend on Kaleido but it isn't clear how to build it)

.include <bsd.port.mk>
