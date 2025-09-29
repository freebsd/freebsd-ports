PORTNAME=	ddgs
DISTVERSION=	9.6.0
CATEGORIES=	www
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Search for words/documents/images/videos/news/maps/text translation
WWW=		https://github.com/deedy5/duckduckgo_search

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USES=		python gmake
USE_PYTHON=	pep517 autoplist

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}click>0:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}primp>=0.15.0:www/py-primp@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lxml>=6.0.0:devel/py-lxml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}httpx>=0.28.1:www/py-httpx@${PY_FLAVOR}

NO_ARCH=	yes

.include <bsd.port.mk>
