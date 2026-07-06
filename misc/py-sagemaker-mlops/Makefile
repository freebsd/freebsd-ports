PORTNAME=	sagemaker-mlops
DISTVERSION=	1.15.0
CATEGORIES=	misc python # machine-learning
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/}-${PORTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	SageMaker: MLOps package for workflow orchestration
WWW=		https://github.com/aws/sagemaker-python-sdk

LICENSE=	APACHE20

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}boto3>=1.42.2<2.0:www/py-boto3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}botocore>=1.42.2<2.0:devel/py-botocore@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cryptography>=46.0.0:security/py-cryptography@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyarrow>=14.0.0:databases/py-pyarrow@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyiceberg>=0.8.0:databases/py-pyiceberg@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}s3fs>=0:filesystems/py-s3fs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sagemaker-core>=2.14.0:misc/py-sagemaker-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sagemaker-serve>=1.14.0:misc/py-sagemaker-serve@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sagemaker-train>=1.14.0:misc/py-sagemaker-train@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist

NO_ARCH=	yes

post-stage:
	@${RM} ${STAGEDIR}${PYTHON_SITELIBDIR}/sagemaker/__init__.py
	@${RM} ${STAGEDIR}${PYTHON_SITELIBDIR}/sagemaker/__pycache__/__init__*.pyc
	@${RMDIR} ${STAGEDIR}${PYTHON_SITELIBDIR}/sagemaker/__pycache__ 2>/dev/null || true

POST_PLIST=	fix-plist

fix-plist:
	@${REINPLACE_CMD} -e '/sagemaker\/__init__/d' ${TMPPLIST}
	@${REINPLACE_CMD} -e '/sagemaker\/__pycache__/d' ${TMPPLIST}

.include <bsd.port.mk>
