PORTNAME=	pyexcel
PORTVERSION=	0.7.4
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Provide one API to read, manipulate and writedata in different excel formats
WWW=		https://github.com/pyexcel/pyexcel

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}lml>=0.2.0:devel/py-lml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyexcel-io>=0.6.2:textproc/py-pyexcel-io@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}texttable>=0.8.2:textproc/py-texttable@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

OPTIONS_DEFINE=	ODS XLS XLSX
OPTIONS_DEFAULT=ODS XLS XLSX
ODS_DESC=	OpenDocument spreadsheet (.ods) support
XLS_DESC=	Microsoft Excel 97-2003 (.xls) support
XLSX_DESC=	Microsoft Excel 2007- (.xlsx) support

ODS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyexcel-ods3>=0.6.0:textproc/py-pyexcel-ods3@${PY_FLAVOR}
XLS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyexcel-xls>=0.6.0:textproc/py-pyexcel-xls@${PY_FLAVOR}
XLSX_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyexcel-xlsx>=0.6.0:textproc/py-pyexcel-xlsx@${PY_FLAVOR}

.include <bsd.port.mk>
