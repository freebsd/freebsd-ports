# Created by: Kozlov Sergey <kozlov.sergey.404@gmail.com>
# $FreeBSD$

PORTNAME=	django-tables2
DISTVERSION=	2.2.1
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}dj22-

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Table/data-grid framework for Django

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django22>=0:www/py-django22@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tablib>=0:textproc/py-tablib@${PY_FLAVOR}

USES=		python:3.5+
USE_PYTHON=	distutils autoplist

NO_ARCH=		yes
CONFLICTS_INSTALL=	${PYTHON_PKGNAMEPREFIX}django-tables2 \
			${PYTHON_PKGNAMEPREFIX}dj21-django-tables2

.include <bsd.port.mk>
