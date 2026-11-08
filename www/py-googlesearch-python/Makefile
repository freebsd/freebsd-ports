PORTNAME=	googlesearch-python
DISTVERSION=	1.3.0
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	googlesearch_python-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python library for scraping the Google search engine
WWW=		https://github.com/Nv7-GitHub/googlesearch

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}beautifulsoup4>=4.9:www/py-beautifulsoup4@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.20:www/py-requests@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

.include <bsd.port.mk>
