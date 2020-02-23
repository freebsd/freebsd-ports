# Created by: Kurt Lidl <kurt.lidl@cello.com>
# $FreeBSD$

PORTNAME=	django-appmedia
PORTVERSION=	1.0.1
PORTREVISION=	4
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	kurt.lidl@cello.com
COMMENT=	Serve static content from within django app directories

DEPRECATED=	Uses deprecated version of python
EXPIRATION_DATE=	2020-08-15

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/django/bin/django-admin.py:www/py-django111@${PY_FLAVOR}

USES=		python:2.7
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
