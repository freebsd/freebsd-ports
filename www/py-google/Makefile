PORTNAME=	google
DISTVERSION=	3.0.0
PORTREVISION=	2
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python bindings to the Google search engine
WWW=		https://breakingcode.wordpress.com/

LICENSE=	BSD2CLAUSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}beautifulsoup4>=4:www/py-beautifulsoup4@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils
NO_ARCH=	yes

.include <bsd.port.mk>
