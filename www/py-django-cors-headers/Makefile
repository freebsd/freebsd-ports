# $FreeBSD$

PORTNAME=	django-cors-headers
PORTVERSION=	2.5.3
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Handles server headers required for Cross-Origin Resource Sharing

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django111>0:www/py-django111@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist

NO_ARCH=	yes
CONFLICTS_INSTALL=	${PYTHON_PKGNAMEPREFIX}dj21-django-cors-headers

.include <bsd.port.mk>
