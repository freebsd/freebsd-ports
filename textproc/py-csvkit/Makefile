PORTNAME=	csvkit
PORTVERSION=	2.1.0
PORTREVISION=	1
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	matthew@FreeBSD.org
COMMENT=	Command line tools for working with CSV
WWW=		https://csvkit.readthedocs.io/

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}agate>=1.6.3:textproc/py-agate@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}agate-excel>=0.2.2:textproc/py-agate-excel@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}agate-dbf>=0.2.2:textproc/py-agate-dbf@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}agate-sql>=0.5.3:databases/py-agate-sql@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openpyxl>=0:textproc/py-openpyxl@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlalchemy20>=0:databases/py-sqlalchemy20@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}xlrd>=0:textproc/py-xlrd@${PY_FLAVOR}

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest-cov>=0:devel/py-pytest-cov@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}coverage>=4.4.2:devel/py-coverage@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils pytest
NO_ARCH=	yes

# Failures of the two listed tests are due to sqlite and not the csvkit code itself.
#
# E       sqlalchemy.exc.OperationalError: (sqlite3.OperationalError) no such column: Chicago%
# E       [SQL: SELECT text FROM testfixed_converted WHERE text LIKE "Chicago%"]
# E       (Background on this error at: https://sqlalche.me/e/20/e3q8)
#
# >       self.assertEqual(output, '9,748.346\n')
# E       AssertionError: '9748.346\n' != '9,748.346\n'
# E       - 9748.346
# E       + 9,748.346
# E       ?  +

PYTEST_BROKEN_TESTS=	test_query_text test_decimal_format

.include <bsd.port.mk>
