PORTNAME=	docling-google-ocr
DISTVERSION=	2.13.1
PORTREVISION=	1
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/g}-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	SDK and CLI for parsing PDF, DOCX, HTML, and more into unified format
WWW=		https://github.com/DS4SD/docling

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}poetry-core>=0:devel/py-poetry-core@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}beautifulsoup4>=0:www/py-beautifulsoup4@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}certifi>=2024.7.4:security/py-certifi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}deepsearch-glm>=1.0.0:textproc/py-deepsearch-glm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}docling-core>=2.12.1:textproc/py-docling-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}docling-ibm-models>=3.1.0:textproc/py-docling-ibm-models@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}docling-parse>=3.0.0:textproc/py-docling-parse@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}easyocr>=1.7:graphics/py-easyocr@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}filetype>=1.2.0:devel/py-filetype@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}google-api-core>=2.13.0:www/py-google-api-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}google-auth>=2.23.4:security/py-google-auth@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}google-cloud-vision>=3.4.5:www/py-google-cloud-vision@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}googleapis-common-protos>=1.61.0:devel/py-googleapis-common-protos@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}huggingface-hub>=0.23:misc/py-huggingface-hub@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lxml>=4.0.0:devel/py-lxml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}marko>=2.1.2:textproc/py-marko@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openpyxl>=3.1.5:textproc/py-openpyxl@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pandas>=2.1.4:math/py-pandas@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydantic2>=2.0.0:devel/py-pydantic2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydantic-settings>=2.3.0:devel/py-pydantic-settings@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-docx>=1.1.2:textproc/py-python-docx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-pptx>=1.0.2:textproc/py-python-pptx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.32.3:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rtree>=1.3.0:devel/py-rtree@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>=1.6.0:science/py-scipy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typer>=0.12.5:devel/py-typer@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
