# $FreeBSD$

PORTNAME=	django-cors-headers
PORTVERSION=	3.2.0
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}dj21-

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Handles server headers required for Cross-Origin Resource Sharing

LICENSE=	MIT

DEPRECATED=		Django 2.1 is now End-of-Life (Since December 2 2019) and no longer supported. Switch to Django 2.2+ versions of this port as soon as possible
EXPIRATION_DATE=	2020-01-31

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django21>0:www/py-django21@${PY_FLAVOR}

USES=		python:3.5+
USE_PYTHON=	distutils autoplist

NO_ARCH=	yes
CONFLICTS_INSTALL=	${PYTHON_PKGNAMEPREFIX}django-cors-headers \
			${PYTHON_PKGNAMEPREFIX}dj22-django-cors-headers

.include <bsd.port.mk>
