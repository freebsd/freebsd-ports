PORTNAME=	ocrmypdf
DISTVERSION=	16.10.4
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Adds an OCR text layer to scanned PDF files
WWW=		https://github.com/ocrmypdf/OCRmyPDF

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>0:devel/py-hatchling@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hatch-vcs>0:devel/py-hatch-vcs@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}deprecation>=2.1.0:devel/py-deprecation@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}img2pdf>=0.5:graphics/py-img2pdf@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>=20:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pillow>=10.0.1:graphics/py-pillow@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pillow-heif>0:graphics/py-pillow-heif@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rich>=13:textproc/py-rich@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pdfminer.six>=20220319:textproc/py-pdfminer.six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pikepdf>=8.10.1:textproc/py-pikepdf@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pluggy>=1:devel/py-pluggy@${PY_FLAVOR} \
		tesseract:graphics/tesseract
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hypothesis>=6.36.0:devel/py-hypothesis@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-xdist>=2.5.0:devel/py-pytest-xdist@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-xmp-toolkit>=2.0.1:textproc/py-python-xmp-toolkit@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}reportlab>=3.6.8:print/py-reportlab@${PY_FLAVOR}

USES=		ghostscript:run python:3.10+ shebangfix
USE_PYTHON=	autoplist concurrent pep517 pytest
# Skip some checks as they yield wrong results if run with the root account
PYTEST_IGNORED_TESTS=	test_chmod \
			test_input_file_not_readable \
			test_malformed_docinfo # leads to an internal pytest error

SHEBANG_FILES=	src/ocrmypdf/__main__.py \
		src/ocrmypdf/pdfinfo/__init__.py

TEST_ARGS=	-n ${MAKE_JOBS_NUMBER}
TEST_ENV=	PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

NO_ARCH=	yes

PLIST_FILES=	etc/bash_completion.d/ocrmypdf.bash share/fish/vendor_completions.d/ocrmypdf.fish

OPTIONS_DEFINE=	PNGQUANT UNPAPER
OPTIONS_DEFAULT=PNGQUANT UNPAPER

PNGQUANT_DESC=	Optimizes the encoding of PNG-style images in PDFs
UNPAPER_DESC=	Deskew and clean up pages before OCR processing

PNGQUANT_RUN_DEPENDS=	pngquant:graphics/pngquant
UNPAPER_RUN_DEPENDS=	unpaper:graphics/unpaper

post-install:
	# Install shell completion files
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/bash_completion.d ${STAGEDIR}${PREFIX}/share/fish/vendor_completions.d/
	${INSTALL_DATA} ${WRKSRC}/misc/completion/ocrmypdf.bash ${STAGEDIR}${PREFIX}/etc/bash_completion.d/
	${INSTALL_DATA} ${WRKSRC}/misc/completion/ocrmypdf.fish ${STAGEDIR}${PREFIX}/share/fish/vendor_completions.d/

.include <bsd.port.mk>
