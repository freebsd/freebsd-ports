PORTNAME=	pandas-datareader
DISTVERSION=		0.11.1
CATEGORIES=	math finance python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:C/-/_/}-${DISTVERSION}

MAINTAINER=	FreeBSD@Shaneware.biz
COMMENT=	Data readers previously found in Pandas
WWW=		https://github.com/pydata/pandas-datareader

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
				${PYTHON_PKGNAMEPREFIX}setuptools-scm>=8:devel/py-setuptools-scm@${PY_FLAVOR} \
				${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}lxml>0:devel/py-lxml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pandas>=2.1.4:math/py-pandas@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.19.0:www/py-requests@${PY_FLAVOR}

USES=		dos2unix python
DOS2UNIX_FILES=	pyproject.toml
USE_PYTHON=	autoplist pep517 pytest

NO_ARCH=	yes

do-test: # some testcases are known to fail: https://github.com/pydata/pandas-datareader/issues/500
	@cd ${WRKSRC} && ${PYTHON_CMD} -m pytest pandas_datareader/tests

.include <bsd.port.mk>
