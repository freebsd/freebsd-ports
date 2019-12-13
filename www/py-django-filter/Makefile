# $FreeBSD$

PORTNAME=	django-filter
DISTVERSION=	2.2.0
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Dynamic filtering for querysets with Django

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django111>=1.11:www/py-django111@${PY_FLAVOR}

USES=		python:3.5+
USE_PYTHON=	distutils autoplist

NO_ARCH=		yes
CONFLICTS_INSTALL=	${PYTHON_PKGNAMEPREFIX}dj21-django-filter \
			${PYTHON_PKGNAMEPREFIX}dj22-django-filter

.include <bsd.port.mk>
