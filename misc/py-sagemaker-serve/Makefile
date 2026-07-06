PORTNAME=	sagemaker-serve
DISTVERSION=	1.15.0
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
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}boto3>=1.42.2<2.0:www/py-boto3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}botocore>=1.35.75<2.0:devel/py-botocore@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}deepdiff>0:devel/py-deepdiff@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mlflow-skinny>0:misc/py-mlflow-skinny@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}onnx>0:misc/py-onnx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}psutil>=0:sysutils/py-psutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytorch>0:misc/py-pytorch@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sagemaker-core>=2.14.0:misc/py-sagemaker-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sagemaker-schema-inference-artifacts>=0:misc/py-sagemaker-schema-inference-artifacts@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sagemaker-train>=1.14.0:misc/py-sagemaker-train@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tqdm>0:misc/py-tqdm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tritonclient>0:misc/py-tritonclient@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist

NO_ARCH=	yes

# tests as of 1.15.0: no tests defined

OPTIONS_DEFINE=	ONNXRUNTIME
OPTIONS_DEFAULT=	# empty
ONNXRUNTIME_DESC=	ONNX Runtime support (currently broken, disable to build)
ONNXRUNTIME_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}onnxruntime>0:misc/py-onnxruntime@${PY_FLAVOR}

post-stage:
	@${RM} ${STAGEDIR}${PYTHON_SITELIBDIR}/sagemaker/__init__.py
	@${RM} ${STAGEDIR}${PYTHON_SITELIBDIR}/sagemaker/__pycache__/__init__*.pyc
	@${RMDIR} ${STAGEDIR}${PYTHON_SITELIBDIR}/sagemaker/__pycache__ 2>/dev/null || true

POST_PLIST=	fix-plist

fix-plist:
	@${REINPLACE_CMD} -e '/sagemaker\/__init__/d' ${TMPPLIST}
	@${REINPLACE_CMD} -e '/sagemaker\/__pycache__/d' ${TMPPLIST}

.include <bsd.port.mk>
