# Created by: Johannes Meixner <johannes@perceivon.net>
# $FreeBSD$

PORTNAME=	django-debug-toolbar
PORTVERSION=	2.1
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}dj22-

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Configurable set of panels to display debug information

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=	Obsolete, please use www/py-django-debug-toolbar instead

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django22>=1.11:www/py-django22@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlparse>=0.2.0:databases/py-sqlparse@${PY_FLAVOR}

USES=		python:3.5+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=		yes
CONFLICTS_INSTALL=	${PYTHON_PKGNAMEPREFIX}django-debug-toolbar

.include <bsd.port.mk>
