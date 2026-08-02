PORTNAME=	toil
DISTVERSION=	9.5.0
CATEGORIES=	misc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Pipeline management software for clusters
WWW=		https://github.com/DataBiosphere/toil

LICENSE=	APACHE20

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}addict>=2.2.1:devel/py-addict@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}coloredlogs>=15:devel/py-coloredlogs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}configargparse>=1.7:devel/py-configargparse@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dill>=0.3.2:devel/py-dill@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}docker>=6.1.0:sysutils/py-docker@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}enlighten>=1.5.2:devel/py-enlighten@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}prompt-toolkit>=3.0:devel/py-prompt-toolkit@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}psutil>=6.1.0:sysutils/py-psutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}PyPubSub>=4.0.3:devel/py-PyPubSub@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-dateutil>0:devel/py-python-dateutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>=6:devel/py-pyyaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ruamel.yaml>=0.15:devel/py-ruamel.yaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>=4.6.2:devel/py-typing-extensions@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}urllib3>=1.26.0:net/py-urllib3@${PY_FLAVOR}
#RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}mypy-boto3-s3>=1.28.3:devel/py-mypy-boto3-s3@${PY_FLAVOR} \
#		${PYTHON_PKGNAMEPREFIX}boto3-stubs>=1.28.3:www/py-boto3-stubs@${PY_FLAVOR} \
#		${PYTHON_PKGNAMEPREFIX}moto>=5.0.3:devel/py-moto@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest-cov>0:devel/py-pytest-cov@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}boto3>0:www/py-boto3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}libcloud>=0.14.0:net/py-libcloud@${PY_FLAVOR}

USES=		python shebangfix
USE_PYTHON=	distutils concurrent autoplist pytest

SHEBANG_FILES=	src/toil/test/cwl/mock_mpi/fake_mpi_run.py \
		src/toil/test/docs/scripts/example_cachingbenchmark.py

NO_ARCH=	yes

.include <bsd.port.mk>
