PORTNAME=	pyexcel
PORTVERSION=	0.7.0
CATEGORIES=	textproc python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Provide one API to read, manipulate and writedata in different excel formats

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}chardet>=0,1:textproc/py-chardet@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lml>=0.0.4:devel/py-lml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyexcel-io>=0.6.2:textproc/py-pyexcel-io@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}texttable>=0.8.2:textproc/py-texttable@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

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
