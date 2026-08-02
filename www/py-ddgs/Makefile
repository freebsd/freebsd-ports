PORTNAME=	ddgs
DISTVERSIONPREFIX=	v
DISTVERSION=	9.14.4
CATEGORIES=	www
#MASTER_SITES=	PYPI # no tests
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Search for words/documents/images/videos/news/maps/text translation
WWW=		https://github.com/deedy5/duckduckgo_search

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}click>=8.1.8:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}fake-useragent>=2.2.0:www/py-fake-useragent@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}httpx>=0.28.1:www/py-httpx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lxml>=4.9.4:devel/py-lxml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}primp>=1.2.3:www/py-primp@${PY_FLAVOR}

USES=		python gmake
USE_PYTHON=	pep517 autoplist pytest

USE_GITHUB=	yes
GH_ACCOUNT=	deedy5
GH_PROJECT=	duckduckgo_search

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}

NO_ARCH=	yes

# tests as of 9.6.1: 1 failed, 16 passed, 1 skipped in 49.04s, see https://github.com/deedy5/ddgs/issues/481

.include <bsd.port.mk>
