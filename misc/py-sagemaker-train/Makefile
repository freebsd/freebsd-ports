PORTNAME=	sagemaker-train
DISTVERSION=	1.10.1
CATEGORIES=	misc python # machine-learning
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/}-${PORTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	SageMaker: Amazon Training Toolkit
WWW=		https://github.com/aws/sagemaker-training-toolkit

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}graphene>=3:devel/py-graphene@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Jinja2>=3.0:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}nest-asyncio>=1.5.0:devel/py-nest-asyncio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}paramiko>=2.11.0:security/py-paramiko@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sagemaker-core>=2.10.1:misc/py-sagemaker-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tblib>=1.7.0:devel/py-tblib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>=4.9.0:devel/py-typing-extensions@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>=6.0:devel/py-pyyaml@${PY_FLAVOR}

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
