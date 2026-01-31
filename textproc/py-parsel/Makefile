PORTNAME=	parsel
DISTVERSION=	1.11.0
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	eric@camachat.org
COMMENT=	Library to extract data from HTML and XML using XPath and CSS selectors
WWW=		https://github.com/scrapy/parsel

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}hatchling>=1.27.0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cssselect>=1.2.0:www/py-cssselect@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jmespath>=1.0.0:devel/py-jmespath@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lxml>=2.3:devel/py-lxml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>=23.0:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}w3lib>=1.19.0:www/py-w3lib@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517

NO_ARCH=	yes

.include <bsd.port.mk>
