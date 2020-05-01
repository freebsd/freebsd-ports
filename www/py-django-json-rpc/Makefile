# Created by: John Hixson <john@ixsystems.com>
# $FreeBSD$

PORTNAME=	django-json-rpc
PORTVERSION=	0.7.2
PORTREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jhixson@FreeBSD.org
COMMENT=	Simple JSON-RPC implementation for Django

DEPRECATED=	No longer maintained, not compatible with Django 2.0+
EXPIRATION_DATE=	2020-06-01

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/django/bin/django-admin.py:www/py-django111@${PY_FLAVOR}

LICENSE=	MIT

USES=		python
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
