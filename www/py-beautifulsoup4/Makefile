PORTNAME=	beautifulsoup4
PORTVERSION=	4.15.0
PORTREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	michaelo@FreeBSD.org
COMMENT=	HTML/XML Parser for Python
WWW=		https://www.crummy.com/software/BeautifulSoup/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>0:devel/py-hatchling@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}typing-extensions>=0:devel/py-typing-extensions@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}soupsieve>=1.2:www/py-soupsieve@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lxml>=0:devel/py-lxml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}html5lib>=0:www/py-html5lib@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517 pytest
NO_ARCH=	yes

PLIST_SUB=	BS_VER=${PORTVERSION}

.include <bsd.port.mk>
