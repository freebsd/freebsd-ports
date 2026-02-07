PORTNAME=	pandas-datareader
DISTVERSION=		0.9.0
PORTREVISION=	4
CATEGORIES=	math finance python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	FreeBSD@Shaneware.biz
COMMENT=	Data readers previously found in Pandas
WWW=		https://github.com/pydata/pandas-datareader

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}lxml>0:devel/py-lxml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pandas>0.19.2:math/py-pandas@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.3.0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests-file>0:www/py-requests-file@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests-ftp>0:ftp/py-requests-ftp@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wrapt>0:devel/py-wrapt@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist

NO_ARCH=	yes

do-test: # some testcases are known to fail: https://github.com/pydata/pandas-datareader/issues/500
	@cd ${WRKSRC} && ${PYTHON_CMD} -m pytest pandas_datareader/tests

.include <bsd.port.mk>
