# $FreeBSD$

PORTNAME=	ocrmypdf
DISTVERSION=	9.8.0
CATEGORIES=	textproc python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Adds an OCR test layer to scanned PDF files

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cffi>=1.9.1:devel/py-cffi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-runner>=0:devel/py-pytest-runner@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools_scm>=0:devel/py-setuptools_scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools_scm_git_archive>=0:devel/py-setuptools_scm_git_archive@${PY_FLAVOR}
LIB_DEPENDS=	liblept.so:graphics/leptonica
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cffi>=1.9.1:devel/py-cffi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}img2pdf>=0.3.0,<0.4:graphics/py-img2pdf@${PY_FLAVOR} \
		${PY_PILLOW} \
		${PYTHON_PKGNAMEPREFIX}tqdm>=4:misc/py-tqdm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}reportlab>=3.3.0:print/py-reportlab@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}chardet>=3.0.4,<4:textproc/py-chardet@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pdfminer.six>=20181108:textproc/py-pdfminer.six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pikepdf>=1.8.1<2:textproc/py-pikepdf@${PY_FLAVOR} \
		tesseract:graphics/tesseract
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>=4.4.1:devel/py-pytest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-helpers-namespace>=2019.1.8:devel/py-pytest-helpers-namespace@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-xdist>=1.29.0:devel/py-pytest-xdist@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-cov>=2.8.0:devel/py-pytest-cov@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-xmp-toolkit>=2.0.1:textproc/py-python-xmp-toolkit@${PY_FLAVOR}

USES=		ghostscript:run python:3.6+ shebangfix
USE_LOCALE=	en_US.UTF-8
USE_PYTHON=	autoplist concurrent distutils

SHEBANG_FILES=	src/ocrmypdf/__main__.py \
		src/ocrmypdf/hocrtransform.py \
	       	src/ocrmypdf/leptonica.py \
		src/ocrmypdf/pdfinfo/__init__.py \
		tests/spoof/gs_feature_elision.py \
		tests/spoof/gs_pdfa_failure.py \
		tests/spoof/tesseract_big_image_error.py \
		tests/spoof/tesseract_cache.py \
		tests/spoof/tesseract_noop.py \
		tests/spoof/unpaper_oldversion.py \
		tests/spoof/gs_render_failure.py \
		tests/spoof/gs_raster_failure.py \
		tests/spoof/tesseract_crash.py

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

do-test:
	# Skip some checks as they yield wrong results if run with the root account
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${PYTHON_CMD} -m pytest -rs -v \
	       	-n ${MAKE_JOBS_NUMBER} -k ' \
		not test_dev_null \
		and not test_input_file_not_readable \
		and not test_chmod'

.include <bsd.port.mk>
