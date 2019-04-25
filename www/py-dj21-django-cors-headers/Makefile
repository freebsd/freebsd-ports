# $FreeBSD$

PORTNAME=	django-cors-headers
PORTVERSION=	2.5.2
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}dj21-

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Handles server headers required for Cross-Origin Resource Sharing

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django21>0:www/py-django21@${PY_FLAVOR}

USES=		python:3.5+
USE_PYTHON=	distutils autoplist

NO_ARCH=	yes
CONFLICTS_INSTALL=	${PYTHON_PKGNAMEPREFIX}django-cors-headers

.include <bsd.port.mk>
