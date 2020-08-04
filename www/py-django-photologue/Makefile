# Created by: Kevin Golding <ports@caomhin.org>
# $FreeBSD$

PORTNAME=	django-photologue
PORTVERSION=	3.12
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@caomhin.org
COMMENT=	Powerful image management and gallery application for Django

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django22>=1.11:www/py-django22@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django-sortedm2m>=3.0.0:www/py-django-sortedm2m@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ExifRead>=2.1.2:graphics/py-exifread@${PY_FLAVOR} \
		${PY_PILLOW}

USES=		python:3.6+ # Required as www/py-django-sortedm2m needs Python 3.6+
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

.include <bsd.port.mk>
