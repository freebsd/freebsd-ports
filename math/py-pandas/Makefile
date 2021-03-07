# $FreeBSD$

PORTNAME=	pandas
PORTVERSION=	1.2.0
PORTEPOCH=	1
CATEGORIES=	math devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Flexible, high-performance data analysis in Python

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cython>=0.29.21<3:lang/cython@${PY_FLAVOR} \
		${PYNUMPY}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cython>=0.29.21<3:lang/cython@${PY_FLAVOR} \
		${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}dateutil>=2.7.3:devel/py-dateutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytz>=2017.3,1:devel/py-pytz@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${PY_FLAVOR}

USES=		python:3.7+
USE_PYTHON=	autoplist cython distutils

OPTIONS_DEFINE=		MPL SCIPY
OPTIONS_GROUP=		ACCEL STORAGE HTML EXCEL
OPTIONS_RADIO=		SQL
OPTIONS_GROUP_ACCEL=	BTLNCK NUMEXPR
OPTIONS_GROUP_STORAGE=	BOTO TABLES
OPTIONS_GROUP_HTML=	LXML HTML5LIB JINJA2
OPTIONS_GROUP_EXCEL=	XLRD XLWT OPENPYXL XLSX
OPTIONS_RADIO_SQL=	ALCHEMY10 ALCHEMY11 ALCHEMY12 ALCHEMY13
OPTIONS_DEFAULT=	BTLNCK NUMEXPR

# Note: we cannot include the following ports in *_DEPENDS because they depend
# on us for BUILD and RUN.
#	devel/py-xarray
#	math/py-statsmodels
ACCEL_DESC=	Computation Acceleration Add-ons
ALCHEMY10_DESC=	Support SQL databases via databases/py-sqlalchemy10
ALCHEMY11_DESC=	Support SQL databases via databases/py-sqlalchemy11
ALCHEMY12_DESC=	Support SQL databases via databases/py-sqlalchemy12
ALCHEMY13_DESC=	Support SQL databases via databases/py-sqlalchemy13
BOTO_DESC=	Support Amazon S3 storage via devel/py-boto
BTLNCK_DESC=	Accelerate certain NaN evals via math/py-bottleneck
EXCEL_DESC=	MS Excel I/O Add-ons
HTML5LIB_DESC=	Parse HTML with www/py-html5lib and www/py-beautifulsoup
HTML_DESC=	HTML Parsing/Generation Add-ons
JINJA2_DESC=	Support conditional HTML formatting with devel/py-Jinja2
LXML_DESC=	Parse HTML with devel/py-lxml and www/py-beautifulsoup
MPL_DESC=	Support graphical plotting output via math/py-matplotlib
NUMEXPR_DESC=	Accelerate certain numerical ops via math/py-numexpr
OPENPYXL_DESC=	Write MS Excel 2007+ with textproc/py-openpyxl
OPENPYXL_IMPLIES=	XLRD
SCIPY_DESC=	Support various statistical functions via science/py-scipy
SQL_DESC=	SQLAlchemy ORM Add-ons
STORAGE_DESC=	Data Storage Add-ons
TABLES_DESC=	Support HDF5-based storage via devel/py-tables
XLRD_DESC=	Read MS Excel with textproc/py-xlrd
XLSX_DESC=	Write MS Excel with textproc/py-xlsxwriter
XLWT_DESC=	Write MS Excel with textproc/py-xlwt

ALCHEMY10_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlalchemy10>0:databases/py-sqlalchemy10@${PY_FLAVOR}
ALCHEMY11_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlalchemy11>0:databases/py-sqlalchemy11@${PY_FLAVOR}
ALCHEMY12_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlalchemy12>0:databases/py-sqlalchemy12@${PY_FLAVOR}
ALCHEMY13_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlalchemy13>0:databases/py-sqlalchemy13@${PY_FLAVOR}
BOTO_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}boto>0:devel/py-boto@${PY_FLAVOR}
BTLNCK_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}bottleneck>=1.2.0:math/py-bottleneck@${PY_FLAVOR}
HTML5LIB_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}beautifulsoup>=4.2.1:www/py-beautifulsoup@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}html5lib>0:www/py-html5lib@${PY_FLAVOR}
JINJA2_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Jinja2>0:devel/py-Jinja2@${PY_FLAVOR}
LXML_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}beautifulsoup>=4.2.1:www/py-beautifulsoup@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}lxml>0:devel/py-lxml@${PY_FLAVOR}
MPL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}matplotlib>=2.0.0:math/py-matplotlib@${PY_FLAVOR}
NUMEXPR_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numexpr>=2.6.1:math/py-numexpr@${PY_FLAVOR}
OPENPYXL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}openpyxl>=2.4.0:textproc/py-openpyxl@${PY_FLAVOR}
SCIPY_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}scipy>=1.1:science/py-scipy@${PY_FLAVOR}
TABLES_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}tables>=3.4.2:devel/py-tables@${PY_FLAVOR}
XLRD_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}xlrd>=1.0.0:textproc/py-xlrd@${PY_FLAVOR}
XLSX_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}XlsxWriter>0:textproc/py-xlsxwriter@${PY_FLAVOR}
XLWT_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}xlwt>0:textproc/py-xlwt@${PY_FLAVOR}

post-install:
	${FIND} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR} -name '*.so' -exec ${STRIP_CMD} {} +

.include <bsd.port.mk>
