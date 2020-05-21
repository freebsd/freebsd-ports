# $FreeBSD$

PORTNAME=	django-treebeard
DISTVERSION=	4.3
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}dj22-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Efficient tree implementations for Django

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=	Obsolete after r532093, use www/py-django-treebeard instead

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django22>=0:www/py-django22@${PY_FLAVOR}

USES=		python:3.5+
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

CONFLICTS_INSTALL=	${PYTHON_PKGNAMEPREFIX}django-treebeard

.include <bsd.port.mk>
