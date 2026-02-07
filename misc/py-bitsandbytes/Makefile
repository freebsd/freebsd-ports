PORTNAME=	bitsandbytes
DISTVERSION=	0.47.0
CATEGORIES=	misc # machine-learning
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	k-bit optimizers and matrix multiplication routines
WWW=		https://huggingface.co/docs/bitsandbytes/main/en/index \
		https://github.com/bitsandbytes-foundation/bitsandbytes

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}scikit-build-core>0:devel/py-scikit-build-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}pytorch>0:misc/py-pytorch@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}einops>=0.8.0:misc/py-einops@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lion-pytorch>=0.2.3:misc/py-lion-pytorch@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>=1.11.4:science/py-scipy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}transformers>=4.30.1<5:misc/py-transformers@${PY_FLAVOR}

USES=		cmake:indirect python
USE_PYTHON=	pep517 autoplist pytest

USE_GITHUB=	yes
GH_ACCOUNT=	bitsandbytes-foundation

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/bitsandbytes/libbitsandbytes_cpu.so

.include <bsd.port.mk>
