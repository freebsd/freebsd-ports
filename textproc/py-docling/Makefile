PORTNAME=	docling
DISTVERSION=	2.137.0
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	SDK and CLI for parsing PDF, DOCX, HTML, and more into unified format
WWW=		https://github.com/docling-project/docling/blob/main/CHANGELOG.md

LICENSE=	MIT

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}beautifulsoup4>=4.12.3:www/py-beautifulsoup4@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}certifi>=2024.7.4:security/py-certifi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}defusedxml>=0.7.1:devel/py-defusedxml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}docling-core>=2.98.0:textproc/py-docling-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}docling-parse>=7.22.1:textproc/py-docling-parse@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}docling-slim>=2.137.0:textproc/py-docling-slim@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}filetype>=1.2.0:devel/py-filetype@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}httpx>=0.28:www/py-httpx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mail-parser>=4.1.4:mail/py-mail-parser@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}marko>=2.1.2:textproc/py-marko@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=1.24.0:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openpyxl>=3.1.5:textproc/py-openpyxl@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pillow>=10.0.0:graphics/py-pillow@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pluggy>=1.0.0:devel/py-pluggy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}polyfactory>=2.22.2:devel/py-polyfactory@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydantic-settings>=2.3.0:devel/py-pydantic-settings@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydantic2>=2.0.0:devel/py-pydantic2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pylatexenc>=2.10:textproc/py-pylatexenc@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pypdfium2>=4.30.0:graphics/py-pypdfium2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-docx>=1.2.0:textproc/py-python-docx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-dotenv>=1.0:www/py-python-dotenv@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-pptx>=1.0.2:textproc/py-python-pptx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rapidocr>=3.9.1:graphics/py-rapidocr@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.32.2:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rich>=13.0.0:textproc/py-rich@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rtree>=1.3.0:devel/py-rtree@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>=1.6.0:science/py-scipy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}semchunk>=2.2.0:textproc/py-semchunk@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tree-sitter>=0.25.0:devel/py-tree-sitter@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tree-sitter-c>=0.23.4:devel/py-tree-sitter-c@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tree-sitter-javascript>=0.23.1:devel/py-tree-sitter-javascript@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tree-sitter-python>=0.23.6:devel/py-tree-sitter-python@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tree-sitter-typescript>=0.23.2:devel/py-tree-sitter-typescript@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tqdm>=4.65.0:misc/py-tqdm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typer>=0.19.0:devel/py-typer@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}websockets>=14.0:devel/py-websockets@${PY_FLAVOR}
		#${PYTHON_PKGNAMEPREFIX}python-oxmsg>=0.0.2:mail/py-python-oxmsg@${PY_FLAVOR} # missing

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
