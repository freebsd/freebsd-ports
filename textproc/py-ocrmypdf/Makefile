PORTNAME=	ocrmypdf
DISTVERSION=	13.4.7
CATEGORIES=	textproc python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Adds an OCR text layer to scanned PDF files

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools_scm>=0:devel/py-setuptools_scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools_scm_git_archive>=0:devel/py-setuptools_scm_git_archive@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}coloredlogs>=14.0:devel/py-coloredlogs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}img2pdf>=0.3.0<0.5:graphics/py-img2pdf@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>=20:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pillow>=8.2.0:graphics/py-pillow@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tqdm>=4:misc/py-tqdm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}reportlab>=3.5.66:print/py-reportlab@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pdfminer.six>=20191110:textproc/py-pdfminer.six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pikepdf>=4.0.0:textproc/py-pikepdf@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pluggy>=0.13.0<2.0:devel/py-pluggy@${PY_FLAVOR} \
		tesseract:graphics/tesseract
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>=4.4.1:devel/py-pytest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-xdist>=2.2.0:devel/py-pytest-xdist@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-xmp-toolkit>=2.0.1:textproc/py-python-xmp-toolkit@${PY_FLAVOR}

USES=		ghostscript:run python:3.7+ shebangfix
USE_LOCALE=	en_US.UTF-8
USE_PYTHON=	autoplist concurrent distutils

SHEBANG_FILES=	src/ocrmypdf/__main__.py \
		src/ocrmypdf/hocrtransform.py \
		src/ocrmypdf/pdfinfo/__init__.py

NO_ARCH=	yes

PLIST_FILES=	etc/bash_completion.d/ocrmypdf.bash share/fish/vendor_completions.d/ocrmypdf.fish

OPTIONS_DEFINE=	PNGQUANT UNPAPER
OPTIONS_DEFAULT=PNGQUANT UNPAPER

PNGQUANT_DESC=	Optimizes the encoding of PNG-style images in PDFs
UNPAPER_DESC=	Deskew and clean up pages before OCR processing

PNGQUANT_RUN_DEPENDS=	pngquant:graphics/pngquant
UNPAPER_RUN_DEPENDS=	unpaper:graphics/unpaper

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 30800
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}importlib-metadata>=4:devel/py-importlib-metadata@${PY_FLAVOR}
.endif

.if ${PYTHON_REL} < 30900
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}importlib-resources>=5:devel/py-importlib-resources@${PY_FLAVOR}
.endif

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
		and not test_outputtype_none \
		and not test_chmod'

.include <bsd.port.post.mk>
