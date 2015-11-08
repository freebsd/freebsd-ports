# Created by: Cheng-Lung Sung <clsung@FreeBSD.org>
# $FreeBSD$

PORTNAME=	django-pipeline
PORTVERSION=	1.3.25
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Asset (css/js) packaging library for Django

DEPRECATED=	Django 1.4 extended support ended on 2015-10-01
EXPIRATION_DATE=	2015-12-09

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django14>0:${PORTSDIR}/www/py-django14

NO_ARCH=	yes
USES=		python:2
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
