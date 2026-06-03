PORTNAME=	openai-whisper
DISTVERSIONPREFIX=	v
DISTVERSION=	20250625
PORTREVISION=	1
CATEGORIES=	misc python # machine-learning
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Robust Speech Recognition via Large-Scale Weak Supervision
WWW=		https://openai.com/research/whisper \
		https://github.com/openai/whisper

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}more-itertools>0:devel/py-more-itertools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numba>0:devel/py-numba@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=1.16:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tiktoken>0:textproc/py-tiktoken@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytorch>0:misc/py-pytorch@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tqdm>0:misc/py-tqdm@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}scipy>0:science/py-scipy@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 concurrent autoplist pytest # tests use 4+ GB each, several tests fail

USE_GITHUB=	yes
GH_ACCOUNT=	openai
GH_PROJECT=	whisper

NO_ARCH=	yes

# tests as of 20250625: 10 failed, 30 passed, 12 warnings in 1304.50s (0:21:44), all failures are due to "Torch not compiled with CUDA enabled"

.include <bsd.port.mk>
