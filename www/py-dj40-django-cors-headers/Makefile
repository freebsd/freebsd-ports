PORTNAME=	django-cors-headers
PORTVERSION=	3.12.0
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}dj40-

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Handles server headers required for Cross-Origin Resource Sharing

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django40>=3.2:www/py-django40@${PY_FLAVOR}

USES=		python:3.7+
USE_PYTHON=	autoplist distutils

NO_ARCH=		yes
CONFLICTS_INSTALL=	${PYTHON_PKGNAMEPREFIX}*${PORTNAME}

.include <bsd.port.mk>
