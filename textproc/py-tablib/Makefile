PORTNAME=	tablib
PORTVERSION=	3.0.0
CATEGORIES=	textproc python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Format agnostic tabular data library (XLS, JSON, YAML, CSV)

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools_scm>=0:devel/py-setuptools_scm@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${PY_FLAVOR}

USES=		python:3.7+
USE_PYTHON=	distutils autoplist

NO_ARCH=	yes

OPTIONS_DEFINE=	CLI HTML ODS PANDAS XLS XLSX YAML
OPTIONS_DEFAULT=CLI HTML ODS PANDAS XLS XLSX YAML

CLI_DESC=	Command-line support
HTML_DESC=	HTML format support
ODS_DESC=	Open Document .ods support
PANDAS_DESC=	Pandas Dataframe support
XLS_DESC=	Microsoft Excel .xls support
XLSX_DESC=	Microsoft Excel .xlsx support
YAML_DESC=	YAML format support

CLI_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}tabulate>=0:devel/py-tabulate@${PY_FLAVOR}
HTML_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}markuppy>=0:textproc/py-markuppy@${PY_FLAVOR}
ODS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}odfpy>=0:devel/py-odfpy@${PY_FLAVOR}
PANDAS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pandas>=0:math/py-pandas@${PY_FLAVOR}
XLS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}xlrd>=0:textproc/py-xlrd@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}xlwt>=0:textproc/py-xlwt@${PY_FLAVOR}
XLSX_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}openpyxl>=2.6.0:textproc/py-openpyxl@${PY_FLAVOR}
YAML_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}yaml>=0:devel/py-yaml@${PY_FLAVOR}

do-test:
	@cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHON_CMD} -m pytest -v -rs -o addopts=

.include <bsd.port.mk>
