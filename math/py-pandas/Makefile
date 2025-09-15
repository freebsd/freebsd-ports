PORTNAME=	pandas
PORTVERSION=	2.2.3
PORTREVISION=	3
PORTEPOCH=	1
CATEGORIES=	math devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Flexible, high-performance data analysis in Python
WWW=		https://pandas.pydata.org \
		https://pandas.pydata.org/docs/ \
		https://github.com/pandas-dev/pandas

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	meson>=1.2.1:devel/meson@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}meson-python>=0.13.1:devel/meson-python@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=1.26.0,1<2,1:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}versioneer>=0:devel/py-versioneer@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=1.26.0,1<2,1:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-dateutil>=2.8.2:devel/py-python-dateutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytz>=2020.1,1:devel/py-pytz@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlite3>=0:databases/py-sqlite3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tzdata>=2022.7:devel/py-tzdata@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}arrow>=0:devel/py-arrow@${PY_FLAVOR}

USES=		cpe python
USE_PYTHON=	autoplist concurrent cython3 pep517 pytest

CPE_VENDOR=	numfocus

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_WRKSRC=	${WRKSRC}/pandas

OPTIONS_DEFINE=		MPL SCIPY
OPTIONS_GROUP=		ACCEL STORAGE HTML EXCEL
OPTIONS_RADIO=		SQL
OPTIONS_GROUP_ACCEL=	BTLNCK NUMEXPR
OPTIONS_GROUP_STORAGE=	BOTO TABLES
OPTIONS_GROUP_HTML=	LXML HTML5LIB JINJA2
OPTIONS_GROUP_EXCEL=	XLRD XLWT OPENPYXL XLSX
OPTIONS_RADIO_SQL=	ALCHEMY14 ALCHEMY20
OPTIONS_DEFAULT=	BTLNCK NUMEXPR

# Note: we cannot include the following ports in *_DEPENDS because they depend
# on us for BUILD and RUN.
#	devel/py-xarray
#	math/py-statsmodels
ACCEL_DESC=	Computation Acceleration Add-ons
ALCHEMY14_DESC=	Support SQL databases via databases/py-sqlalchemy14
ALCHEMY20_DESC=	Support SQL databases via databases/py-sqlalchemy20
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

ALCHEMY14_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlalchemy14>0:databases/py-sqlalchemy14@${PY_FLAVOR}
ALCHEMY20_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlalchemy20>0:databases/py-sqlalchemy20@${PY_FLAVOR}
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
	@${FIND} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR} -name '*.so' -exec ${STRIP_CMD} {} +

do-test:
	@cd ${TEST_WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHON_CMD} -c "import pandas; pandas.test()"

.include <bsd.port.mk>
