PORTNAME=	textract
PORTVERSION=	1.6.5
PORTREVISION=	7
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	DtxdF@disroot.org
COMMENT=	Extract text from any document
WWW=		https://github.com/deanmalmgren/textract

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}argcomplete>=1.10.0:devel/py-argcomplete@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}chardet>=3:textproc/py-chardet@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>1.12.0:devel/py-six@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

OPTIONS_DEFINE=	ANTIWORD BEAUTIFULSOUP DOCX2TXT MSG LIBXML2 \
		LIBXSLT PPTX PS SPREADSHEET UNRTF
OPTIONS_DEFAULT=ANTIWORD BEAUTIFULSOUP DOCX2TXT FFMPEG FLAC JPEG_TURBO \
		LAME LIBXML2 LIBXSLT MSG PDFTOTEXT PPTX PS SOX \
		SPEECH_RECOGNITION SPREADSHEET TESSERACT UNRTF
OPTIONS_GROUP=	AUDIO OCR PDF RTF
OPTIONS_GROUP_AUDIO=	FFMPEG FLAC LAME POCKETSPHINX SOX SPEECH_RECOGNITION
OPTIONS_GROUP_OCR=	JPEG_TURBO TESSERACT
OPTIONS_GROUP_PDF=	PDFMINER PDFTOTEXT

ANTIWORD_DESC=	DOC document support
BEAUTIFULSOUP_DESC=	HTML parsing library
DOCX2TXT_DESC=	DOCX document support
JPEG_TURBO_DESC=	SIMD-accelerated JPEG codec
LIBXML2_DESC=	Python interface for XML parser library
LIBXSLT_DESC=	XML stylesheet transformation library
MSG_DESC=	MS Outlook MSG file format support
PDFMINER_DESC=	PDF parser and analyzer
PDFTOTEXT_DESC=	Extract text from a PDF document
POCKETSPHINX_DESC=	Interface to CMU Sphinxbase and Pocketsphinx
PPTX_DESC=	MS PowerPoint PPTX presentations support
SOX_DESC=	Command-line audio processing tool
SPEECH_RECOGNITION_DESC=	Python library for performing speech recognition
SPREADSHEET_DESC=	XLS and XLSX spreadsheet support
TESSERACT_DESC=	Commercial quality open source OCR engine
UNRTF_DESC=	RTF document support

ANTIWORD_RUN_DEPENDS=	antiword>0:textproc/antiword
BEAUTIFULSOUP_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}beautifulsoup>=4.8.0:www/py-beautifulsoup@${PY_FLAVOR}
DOCX2TXT_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}docx2txt>=0.8:textproc/py-docx2txt@${PY_FLAVOR}
FFMPEG_RUN_DEPENDS=	ffmpeg>0:multimedia/ffmpeg
FLAC_RUN_DEPENDS=	flac>0:audio/flac
JPEG_TURBO_RUN_DEPENDS=	jpeg-turbo>0:graphics/jpeg-turbo
LAME_RUN_DEPENDS=	lame>0:audio/lame
LIBXML2_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}libxml2>0:textproc/py-libxml2@${PY_FLAVOR}
LIBXSLT_RUN_DEPENDS=	libxslt>=1.1.15:textproc/libxslt
MSG_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}extract-msg>=0.29:textproc/py-extract-msg@${PY_FLAVOR}
PDFMINER_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pdfminer.six>=20191110:textproc/py-pdfminer.six@${PY_FLAVOR}
PDFTOTEXT_RUN_DEPENDS=	poppler-utils>0:graphics/poppler-utils
POCKETSPHINX_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pocketsphinx>0:audio/py-pocketsphinx@${PY_FLAVOR}
PPTX_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}python-pptx>=0.6.18:textproc/py-python-pptx@${PY_FLAVOR}
PS_RUN_DEPENDS=	pstotext>0:print/pstotext
SOX_RUN_DEPENDS=	sox>0:audio/sox
SPEECH_RECOGNITION_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}speechrecognition>=3.8.1:audio/py-speechrecognition@${PY_FLAVOR}
SPREADSHEET_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}xlrd>=1.2.0:textproc/py-xlrd@${PY_FLAVOR}
TESSERACT_RUN_DEPENDS=	tesseract>0:graphics/tesseract
UNRTF_RUN_DEPENDS=	unrtf>0:textproc/unrtf

.include <bsd.port.mk>
