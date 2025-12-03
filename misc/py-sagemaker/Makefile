PORTNAME=	sagemaker
DISTVERSION=	3.0.1
CATEGORIES=	misc python # machine-learning
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	SageMaker: Library for training, deploying models on Amazon SageMaker
WWW=		https://sagemaker.readthedocs.io/en/stable/ \
		https://github.com/aws/sagemaker-python-sdk

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sagemaker-core>=2.0.0<3.0.0:misc/py-sagemaker-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sagemaker-mlops<2.0.0:misc/py-sagemaker-mlops@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sagemaker-serve<2.0.0:misc/py-sagemaker-serve@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sagemaker-train<2.0.0:misc/py-sagemaker-train@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist

NO_ARCH=	yes

.include <bsd.port.mk>
