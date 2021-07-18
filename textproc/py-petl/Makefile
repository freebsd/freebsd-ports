# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	petl
PORTVERSION=	1.7.4
PORTREVISION=	1
CATEGORIES=	textproc python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Extract, transform and load tables of data

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools_scm>=1.5.4:devel/py-setuptools_scm@${PY_FLAVOR}

USES=		python:3.7+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

OPTIONS_DEFINE=	AVRO DB HDF5 HTTP INTERVAL NUMPY PANDAS REMOTE SMB XLS XLSX XPATH WHOOSH
AVRO_DESC=	Avro support
DB_DESC=	Database support
HDF5_DESC=	HDF5 support
HTTP_DESC=	HTTP support
INTERVAL_DESC=	Interval tree support
NUMPY_DESC=	NumPy support
PANDAS_DESC=	Pandas support
REMOTE_DESC=	Remote file system support
SMB_DESC=	Windows and Samba network support
XLS_DESC=	Microsoft Excel .xls support
XLSX_DESC=	Microsoft Excel .xlsx support
XPATH_DESC=	XPath support
WHOOSH_DESC=	Whoosh support

AVRO_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}fastavro>=0.24.0:textproc/py-fastavro@${PY_FLAVOR}
DB_RUN_DEPENDS=		${PYTHON_PKGNAMEPREFIX}sqlalchemy14>=1.3.6:databases/py-sqlalchemy14@${PY_FLAVOR}
HDF5_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cython>=0.29.13:lang/cython@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}numexpr>=2.6.9:math/py-numexpr@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}numpy>=1.16.4,1:math/py-numpy@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}tables>=3.5.2:devel/py-tables@${PY_FLAVOR}
HTTP_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}aiohttp>=3.6.2:www/py-aiohttp@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}requests>=0:www/py-requests@${PY_FLAVOR}
INTERVAL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}intervaltree>=3.0.2:devel/py-intervaltree@${PY_FLAVOR}
NUMPY_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=1.16.4,1:math/py-numpy@${PY_FLAVOR}
PANDAS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pandas>=0.24.2,1:math/py-pandas@${PY_FLAVOR}
REMOTE_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}fsspec>=0.7.4:devel/py-fsspec@${PY_FLAVOR}
SMB_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}smbprotocol>=1.0.1:net/py-smbprotocol@${PY_FLAVOR}
XLS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}xlrd>=1.2.0:textproc/py-xlrd@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}xlwt>=1.3.0:textproc/py-xlwt@${PY_FLAVOR}
XLSX_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}openpyxl>=2.6.2:textproc/py-openpyxl@${PY_FLAVOR}
XPATH_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}lxml>=4.4.0:devel/py-lxml@${PY_FLAVOR}
WHOOSH_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}whoosh>=0:textproc/py-whoosh@${PY_FLAVOR}

.include <bsd.port.mk>
