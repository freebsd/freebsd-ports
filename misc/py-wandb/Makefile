PORTNAME=	wandb
DISTVERSIONPREFIX=	v
DISTVERSION=	0.16.2
CATEGORIES=	misc # machine-learning
#MASTER_SITES=	PYPI # no tests
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	CLI and library for interacting with the Weights and Biases API
WWW=		https://wandb.ai/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

PY_DEPENDS=	${PYTHON_PKGNAMEPREFIX}appdirs>=1.4.3:devel/py-appdirs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}click>=7.1:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}docker-pycreds>=0.4.0:security/py-docker-pycreds@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}gitpython>=1.0.0:devel/py-gitpython@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pathtools>0:devel/py-pathtools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}protobuf>=3.19.0:devel/py-protobuf@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}psutil>=5.0.0:sysutils/py-psutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.0.0,<3:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sentry-sdk>=1.0.0:devel/py-sentry-sdk@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setproctitle>0:devel/py-setproctitle@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>0:devel/py-typing-extensions@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yaml>0:devel/py-yaml@${PY_FLAVOR}
BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR} \
		${PY_DEPENDS}
RUN_DEPENDS=	${PY_DEPENDS}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}bokeh>0:www/py-bokeh@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}matplotlib>0:math/py-matplotlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}nbclient>0:devel/py-nbclient@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}nbformat>0:devel/py-nbformat@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}parameterized>0:devel/py-parameterized@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-cov>0:devel/py-pytest-cov@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-flask>0:devel/py-pytest-flask@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-mock>=1.10.4:devel/py-pytest-mock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-rerunfailures>0:devel/py-pytest-rerunfailures@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-timeout>0:devel/py-pytest-timeout@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-xdist>0:devel/py-pytest-xdist@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}responses>0:devel/py-responses@${PY_FLAVOR}

USES=		python shebangfix
USE_PYTHON=	pep517 concurrent autoplist pytest # tests fail because some test dependencies are missing
USE_GITHUB=	yes

SHEBANG_GLOB=	*.py

NO_ARCH=	yes

.include <bsd.port.mk>
