# Created by: Johannes Meixner <johannes@perceivon.net>
# $FreeBSD$

PORTNAME=	django-debug-toolbar
PORTVERSION=	2.1
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}dj21-

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Configurable set of panels to display debug information

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=		Django 2.1 is now End-of-Life (Since December 2 2019) and no longer supported. Switch to Django 2.2+ versions of this port as soon as possible
EXPIRATION_DATE=	2020-01-31

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django21>=1.11:www/py-django21@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlparse>=0.2.0:databases/py-sqlparse@${PY_FLAVOR}

USES=		python:3.5+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=		yes
CONFLICTS_INSTALL=	${PYTHON_PKGNAMEPREFIX}django-debug-toolbar \
			${PYTHON_PKGNAMEPREFIX}dj22-django-debug-toolbar

.include <bsd.port.mk>
