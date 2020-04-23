# Created by: Matthew X. Economou <xenophon+fbsdports@irtnog.org>
# $FreeBSD$

PORTNAME=	django-filer
PORTVERSION=	1.7.0
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	xenophon+fbsdports@irtnog.org
COMMENT=	File and Image Management Application for django

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django22>=1.11<4.0:www/py-django22@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django-easy-thumbnails>=2<3.0:graphics/py-django-easy-thumbnails@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django-mptt>=0.6<1.0:www/py-django-mptt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django-polymorphic>=0.7<2.2:www/py-django-polymorphic@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}unidecode>=0.04<1.2:converters/py-unidecode@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six@${PY_FLAVOR} \
		${PY_PILLOW}

USES=		python:3.5+
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

.include <bsd.port.mk>
