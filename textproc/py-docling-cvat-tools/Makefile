PORTNAME=	docling-cvat-tools
DISTVERSION=	0.1.0
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/g}-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	CVAT annotation tools for Docling document processing and evaluation
WWW=		https://github.com/docling-project/docling-cvat-tools

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cvat-sdk>=2.40.0:misc/py-cvat-sdk@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}docling>=2.56.1:textproc/py-docling@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}docling-core>=2.63.0:textproc/py-docling-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lxml>=5.3.0:devel/py-lxml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openpyxl>=3.1.5:textproc/py-openpyxl@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pandas>=2.2.3:math/py-pandas@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pillow>=10.3.0:graphics/py-pillow@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydantic2>=2.0.0:devel/py-pydantic2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tqdm>=4.67.1:misc/py-tqdm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typer>=0.16.0:devel/py-typer@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}xlsxwriter>=3.1.0:textproc/py-xlsxwriter@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest-dependency>=0.6:devel/py-pytest-dependency@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517 pytest

NO_ARCH=	yes

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
# sdist lacks tests/data samples
TEST_ARGS=	--disable-plugin-autoload -p dependency \
		--deselect tests/test_cvat_to_docling_converter.py::test_case_02_specific_sample \
		--deselect tests/test_cvat_to_docling_converter.py::test_cvat_to_docling_conversion

# tests as of 0.1.0: 5 passed, 2 deselected in 1.23s

.include <bsd.port.mk>
