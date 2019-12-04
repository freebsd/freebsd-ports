# Created by: Kozlov Sergey <kozlov.sergey.404@gmail.com>
# $FreeBSD$

PORTNAME=	django-tables2
DISTVERSION=	2.0.6
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}dj21-

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Table/data-grid framework for Django

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=		Django 2.1 is now End-of-Life (Since December 2 2019) and no longer supported. Switch to Django 2.2+ versions of this port as soon as possible
EXPIRATION_DATE=	2020-01-31

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django21>=1.11:www/py-django21@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tablib>=0:textproc/py-tablib@${PY_FLAVOR}

USES=		python:3.5+
USE_PYTHON=	distutils autoplist

NO_ARCH=		yes
CONFLICTS_INSTALL=	${PYTHON_PKGNAMEPREFIX}django-tables2 \
			${PYTHON_PKGNAMEPREFIX}dj22-django-tables2

.include <bsd.port.mk>
