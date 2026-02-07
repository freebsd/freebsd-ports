PORTNAME=	tablib
DISTVERSION=	3.9.0
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Format agnostic tabular data library (XLS, JSON, YAML, CSV)
WWW=		https://github.com/jazzband/tablib

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>=6.2:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}

USES=		cpe python
CPE_VENDOR=	python
USE_PYTHON=	autoplist pep517 pytest

NO_ARCH=	yes

OPTIONS_DEFINE=	CLI ODS PANDAS XLS XLSX YAML
OPTIONS_DEFAULT=CLI ODS PANDAS XLS XLSX YAML

CLI_DESC=	Command-line support
ODS_DESC=	Open Document .ods support
PANDAS_DESC=	Pandas Dataframe support
XLS_DESC=	Microsoft Excel .xls support
XLSX_DESC=	Microsoft Excel .xlsx support
YAML_DESC=	YAML format support

CLI_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}tabulate>=0:devel/py-tabulate@${PY_FLAVOR}
ODS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}odfpy>=0:devel/py-odfpy@${PY_FLAVOR}
PANDAS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pandas>=0:math/py-pandas@${PY_FLAVOR}
XLS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}xlrd>=0:textproc/py-xlrd@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}xlwt>=0:textproc/py-xlwt@${PY_FLAVOR}
XLSX_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}openpyxl>=2.6.0:textproc/py-openpyxl@${PY_FLAVOR}
YAML_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyyaml>=0:devel/py-pyyaml@${PY_FLAVOR}

.include <bsd.port.mk>
