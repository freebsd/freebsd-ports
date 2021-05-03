# Created by: Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>

PORTNAME=	django
PORTVERSION=	2.2.13
CATEGORIES=	www python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	python@FreeBSD.org
COMMENT=	High-level Python Web Framework (meta port)

LICENSE=	BSD3CLAUSE

USES=		cpe metaport
CPE_VENDOR=	djangoproject
USE_PYTHON=	flavors

PORTSCOUT=	ignore:1

OPTIONS_DEFAULT=	DJANGO22
OPTIONS_SINGLE=		DJANGO
OPTIONS_SINGLE_DJANGO=	DJANGO22 DJANGO30

DJANGO22_DESC=	Use Django 2.2.x
DJANGO30_DESC=	Use Django 3.0.x

DJANGO22_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django22>=0:www/py-django22@${PY_FLAVOR}
DJANGO22_USES=		python:3.5+,run
DJANGO30_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django30>=0:www/py-django30@${PY_FLAVOR}
DJANGO30_USES=		python:3.6+,run

.include <bsd.port.mk>
