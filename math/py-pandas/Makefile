# $FreeBSD$

PORTNAME=	pandas
DISTVERSION=	0.22.0
PORTREVISION=	1
CATEGORIES=	math devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	john@saltant.com
COMMENT=	Flexible, high-performance data analysis in Python

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	${PYNUMPY}
RUN_DEPENDS:=	${BUILD_DEPENDS} \
		${PYTHON_PKGNAMEPREFIX}dateutil>=1.5:devel/py-dateutil@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytz>0:devel/py-pytz@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${FLAVOR}

OPTIONS_DEFINE=		MPL SCIPY
OPTIONS_GROUP=		ACCEL STORAGE HTML EXCEL
OPTIONS_RADIO=		SQL
OPTIONS_GROUP_ACCEL=	BTLNCK NUMEXPR
OPTIONS_GROUP_STORAGE=	BOTO TABLES
OPTIONS_GROUP_HTML=	LXML HTML5LIB JINJA2
OPTIONS_GROUP_EXCEL=	XLRD XLWT OPENPYXL XLSX
OPTIONS_RADIO_SQL=	ALCHEMY10 ALCHEMY11
OPTIONS_DEFAULT=	BTLNCK NUMEXPR

# Note: we cannot include math/py-statsmodels in *_DEPENDS because it
# depends upon us for BUILD and RUN.

MPL_DESC=	Support graphical plotting output via math/py-matplotlib
SCIPY_DESC=	Support various statistical functions via science/py-scipy
BTLNCK_DESC=	Accelerate certain NaN evals via math/py-bottleneck
NUMEXPR_DESC=	Accelerate certain numerical ops via math/py-numexpr
BOTO_DESC=	Support Amazon S3 storage via devel/py-boto
TABLES_DESC=	Support HDF5-based storage via devel/py-tables
LXML_DESC=	Parse HTML with devel/py-lxml and www/py-beautifulsoup
JINJA2_DESC=	Support conditional HTML formatting with devel/py-Jinja2
HTML5LIB_DESC=	Parse HTML with www/py-html5lib and www/py-beautifulsoup
OPENPYXL_DESC=	Read/write MS Excel 2007+ with textproc/py-openpyxl
XLRD_DESC=	Read MS Excel with textproc/py-xlrd
XLWT_DESC=	Write MS Excel with textproc/py-xlwt
XLSX_DESC=	Write MS Excel with textproc/py-xlsxwriter
ALCHEMY10_DESC=	Support SQL databases via databases/py-sqlalchemy10
ALCHEMY11_DESC=	Support SQL databases via databases/py-sqlalchemy11
ACCEL_DESC=	Computation Acceleration Add-ons
STORAGE_DESC=	Data Storage Add-ons
SQL_DESC=	SQLAlchemy ORM Add-ons
HTML_DESC=	HTML Parsing/Generation Add-ons
EXCEL_DESC=	MS Excel I/O Add-ons

MPL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}matplotlib>1.4.3:math/py-matplotlib@${FLAVOR}
SCIPY_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}scipy>0.14.0:science/py-scipy@${FLAVOR}
BTLNCK_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}bottleneck>1.0.0:math/py-bottleneck@${FLAVOR}
NUMEXPR_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numexpr>=2.4.6:math/py-numexpr@${FLAVOR}
BOTO_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}boto>0:devel/py-boto@${FLAVOR}
TABLES_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}tables>=3.0.0:devel/py-tables@${FLAVOR}

LXML_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}lxml>0:devel/py-lxml@${FLAVOR}
HTML5LIB_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}html5lib>0:www/py-html5lib@${FLAVOR}
JINJA2_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Jinja2>0:devel/py-Jinja2@${FLAVOR}
OPENPYXL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}openpyxl>=2.2.0:textproc/py-openpyxl@${FLAVOR}
XLRD_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}xlrd>0:textproc/py-xlrd@${FLAVOR}
XLWT_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}xlwt>0:textproc/py-xlwt@${FLAVOR}
XLSX_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}XlsxWriter>0:textproc/py-xlsxwriter@${FLAVOR}

ALCHEMY10_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlalchemy10>0:databases/py-sqlalchemy10@${FLAVOR}
ALCHEMY11_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlalchemy11>0:databases/py-sqlalchemy11@${FLAVOR}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MLXML} || ${PORT_OPTIONS:MHTML5LIB}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}beautifulsoup>0:www/py-beautifulsoup@${FLAVOR}
.endif

SUB_FILES=	pkg-message

# Official support for 2.7, 3.5, and 3.6
USES=		python
USE_PYTHON=	autoplist distutils

post-install:
	@${FIND} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR} \
		-name '*.so' -exec ${STRIP_CMD} {} +

.include <bsd.port.mk>
