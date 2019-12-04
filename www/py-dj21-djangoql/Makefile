# $FreeBSD$

PORTNAME=	djangoql
PORTVERSION=	0.13.0
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}dj21-

MAINTAINER=	grembo@FreeBSD.org
COMMENT=	Advanced search language for Django, with auto-completion

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=		Django 2.1 is now End-of-Life (Since December 2 2019) and no longer supported. Switch to Django 2.2+ versions of this port as soon as possible
EXPIRATION_DATE=	2020-01-31

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django21>0:www/py-django21@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ply>=3.8:devel/py-ply@${PY_FLAVOR}

USES=		python:3.5+
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

.include <bsd.port.mk>
