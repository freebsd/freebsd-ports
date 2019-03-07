# Created by: Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
# $FreeBSD$

PORTNAME=	django
PORTVERSION=	1.11.20
CATEGORIES=	www python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	python@FreeBSD.org
COMMENT=	High-level Python Web Framework (meta port)

LICENSE=	BSD3CLAUSE

DEPRECATED=	do not depend on this port

OPTIONS_SINGLE=	DJANGO
OPTIONS_SINGLE_DJANGO=	DJANGO111 DJANGO20 DJANGO21
OPTIONS_DEFAULT=DJANGO111
DJANGO111_DESC=	Use Django 1.11.x
DJANGO20_DESC=	Use Django 2.0.x
DJANGO21_DESC=	USe Django 2.1

PORTSCOUT=	ignore:1

USES=		cpe metaport python:run
USE_PYTHON=	flavors

CPE_VENDOR=	djangoproject

DJANGO111_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django111>=0:www/py-django111@${PY_FLAVOR}
DJANGO20_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django20>=0:www/py-django20@${PY_FLAVOR}
DJANGO21_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django21>=0:www/py-django21@${PY_FLAVOR}

.include <bsd.port.mk>
