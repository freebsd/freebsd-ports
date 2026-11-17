PORTNAME=	docling-glm-ocr
DISTVERSION=	0.7.0
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/g}-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Docling OCR plugin for GLM-OCR
WWW=		https://github.com/DCC-BS/docling-glm-ocr

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}docling>=2.73:textproc/py-docling@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}httpx>=0.27:www/py-httpx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=1.26:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pillow>=10.0:graphics/py-pillow@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517 pytest

NO_ARCH=	yes

# importing torch fails with 'No space available for static Thread Local Storage' unless libc10 is preloaded
TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR} \
		LD_PRELOAD=${PYTHON_SITELIBDIR}/torch/lib/libc10.so
# coverage options from pyproject.toml are overridden to avoid requiring pytest-cov
TEST_ARGS=	--disable-plugin-autoload -o addopts=

# tests as of 0.7.0: 154 passed, 6 skipped, 2 warnings in 12.04s

.include <bsd.port.mk>
