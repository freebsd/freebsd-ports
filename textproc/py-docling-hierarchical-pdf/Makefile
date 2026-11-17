PORTNAME=	docling-hierarchical-pdf
DISTVERSION=	0.2.0
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/g}-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Inference of header hierarchy in the Docling PDF parsing pipeline
WWW=		https://krrome.github.io/docling-hierarchical-pdf/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>=0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}docling>=2.53.0:textproc/py-docling@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=1.19.5:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pymupdf>=1.26.4:print/py-PyMuPDF@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scikit-learn>=1.6.0:science/py-scikit-learn@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517 pytest

NO_ARCH=	yes

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR} \
		LD_PRELOAD=${PYTHON_SITELIBDIR}/torch/lib/libc10.so
# test_result_postprocessor_textpdf_http downloads a sample from the network
TEST_ARGS=	--disable-plugin-autoload \
		--deselect tests/test_postprocessing.py::test_result_postprocessor_textpdf_http

# tests as of 0.2.0: 25 passed, 5 skipped, 1 deselected, 17 warnings in 21.16s

.include <bsd.port.mk>
