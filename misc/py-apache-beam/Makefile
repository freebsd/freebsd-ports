PORTNAME=	apache-beam
DISTVERSION=	2.43.0
PORTREVISION=	2
CATEGORIES=	misc
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Apache Beam SDK for Python
WWW=		https://beam.apache.org/

LICENSE=	APACHE20

PY_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cloudpickle>=2.2.0:devel/py-cloudpickle@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}crcmod>=1.7:devel/py-crcmod@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-dateutil>=2.8.0:devel/py-python-dateutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dill>=0.3.1.1:devel/py-dill@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}fastavro>=0.23.6:textproc/py-fastavro@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}fasteners>=0.3:devel/py-fasteners@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}grpcio>=1.33.1>0:devel/py-grpcio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hdfs>=2.1.0:www/py-hdfs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}httplib2>=0.8:www/py-httplib2@${PY_FLAVOR} \
		${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}orjson<4.0:devel/py-orjson@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}objsize>=0.5.2:devel/py-objsize@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}proto-plus>=1.7.1:devel/py-proto-plus@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}protobuf>=3.12.2:devel/py-protobuf@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydot>=1.2.0:graphics/py-pydot@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pymongo>=3.8.0:databases/py-pymongo@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytz>=2018.3:devel/py-pytz@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}regex>=2020.6.8:textproc/py-regex@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.24.0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>=3.7.0:devel/py-typing-extensions@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zstandard>=0.18.0:archivers/py-zstandard@${PY_FLAVOR}
BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pip>0:devel/py-pip@${PY_FLAVOR} \
		${PY_DEPENDS}
RUN_DEPENDS=	${PY_DEPENDS}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}freezegun>=0.3.12:devel/py-freezegun@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}joblib>=0.3.12:devel/py-joblib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mock>=1.0.1:devel/py-mock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pandas>0:math/py-pandas@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}parameterized>=0.7.1:devel/py-parameterized@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}psycopg2>=2.8.5:databases/py-psycopg2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}PyHamcrest>=1.9:textproc/py-pyhamcrest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-timeout>=1.3.3:devel/py-pytest-timeout@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-xdist>=1.29.0:devel/py-pytest-xdist@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests-mock>=1.7:www/py-requests-mock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tenacity>=5.0.2:devel/py-tenacity@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scikit-learn>=0.20.0:science/py-scikit-learn@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlalchemy14>=1.3:databases/py-sqlalchemy14@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>=3.12:devel/py-pyyaml@${PY_FLAVOR}
		# testcontainers[mysql]>=3.0.3 is also required

USES=		python zip
USE_PYTHON=	autoplist concurrent cryptography_test cython distutils pytest # 5 tests fail, depending on pyarrow, MySqlContainer, threadpoolctl

post-install:
	# strip binaries
	@${FIND} ${STAGEDIR}${PREFIX} -name "*${PYTHON_EXT_SUFFIX}.so" | ${XARGS} ${STRIP_CMD}

.include <bsd.port.mk>
