PORTNAME=	docling-ocr
DISTVERSION=	0.1.0
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/}-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	OCR package using LLM models for text extraction from images
WWW=		https://github.com/FREDERICO23/docling_ocr

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pillow>=8.0.0:graphics/py-pillow@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytorch>=1.10.0:misc/py-pytorch@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}transformers>=4.15.0:misc/py-transformers@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517 pytest

NO_ARCH=	yes

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR} \
		LD_PRELOAD=${PYTHON_SITELIBDIR}/torch/lib/libc10.so
# TestSmolDoclingExtractor patches a nonexistent module attribute, and
# test_batch_process depends on os.listdir() order: both are upstream test bugs
TEST_ARGS=	--disable-plugin-autoload \
		-k 'not TestSmolDoclingExtractor and not (test_batch_process and not test_batch_process_)'

# tests as of 0.1.0: 5 passed, 9 deselected, 1 warning in 0.62s

.include <bsd.port.mk>
