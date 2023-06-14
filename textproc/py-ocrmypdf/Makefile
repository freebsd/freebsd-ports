PORTNAME=	ocrmypdf
DISTVERSION=	14.3.0
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Adds an OCR text layer to scanned PDF files
WWW=		https://github.com/ocrmypdf/OCRmyPDF

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=61:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools_scm>=0:devel/py-setuptools_scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}coloredlogs>=14.0:devel/py-coloredlogs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}deprecation>=2.1.0:devel/py-deprecation@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}img2pdf>=0.3.0:graphics/py-img2pdf@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>=20:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pillow>=8.2.0:graphics/py-pillow@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tqdm>=4:misc/py-tqdm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}reportlab>=3.5.66:print/py-reportlab@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pdfminer.six>=20201018:textproc/py-pdfminer.six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pikepdf>=5.0.1:textproc/py-pikepdf@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pluggy>=0.13.0:devel/py-pluggy@${PY_FLAVOR} \
		tesseract:graphics/tesseract
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hypothesis>=6.0.0:devel/py-hypothesis@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-xdist>=2.2.0:devel/py-pytest-xdist@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-xmp-toolkit>=2.0.1:textproc/py-python-xmp-toolkit@${PY_FLAVOR}

USES=		ghostscript:run python shebangfix
USE_PYTHON=	autoplist concurrent pep517 pytest
# Skip some checks as they yield wrong results if run with the root account
PYTEST_IGNORED_TESTS=	test_chmod \
			test_dev_null \
			test_input_file_not_readable \
			test_outputtype_none

SHEBANG_FILES=	src/ocrmypdf/__main__.py \
		src/ocrmypdf/hocrtransform.py \
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

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 30900
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}importlib-resources>=5:devel/py-importlib-resources@${PY_FLAVOR}
.endif

.if ${PYTHON_REL} < 31000
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}typing-extensions>=4:devel/py-typing-extensions@${PY_FLAVOR}
.endif

post-install:
	# Install shell completion files
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/bash_completion.d ${STAGEDIR}${PREFIX}/share/fish/vendor_completions.d/
	${INSTALL_DATA} ${WRKSRC}/misc/completion/ocrmypdf.bash ${STAGEDIR}${PREFIX}/etc/bash_completion.d/
	${INSTALL_DATA} ${WRKSRC}/misc/completion/ocrmypdf.fish ${STAGEDIR}${PREFIX}/share/fish/vendor_completions.d/

.include <bsd.port.post.mk>
