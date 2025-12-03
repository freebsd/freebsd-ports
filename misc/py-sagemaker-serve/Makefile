PORTNAME=	sagemaker-serve
DISTVERSION=	1.0
CATEGORIES=	misc python # machine-learning
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/}-${PORTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	SageMaker: Library for training & deploying models on Amazon SageMaker
WWW=		https://sagemaker.readthedocs.io/en/stable/ \
		https://github.com/aws/sagemaker-python-sdk

LICENSE=	APACHE20

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}boto3>=1.35.75<2.0:www/py-boto3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}botocore>=1.35.75<2.0:devel/py-botocore@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}psutil>=0:sysutils/py-psutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sagemaker-core>=2.0.0:misc/py-sagemaker-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sagemaker-train>=0.1.0:misc/py-sagemaker-train@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tqdm>=0:misc/py-tqdm@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist

NO_ARCH=	yes

.include <bsd.port.mk>
