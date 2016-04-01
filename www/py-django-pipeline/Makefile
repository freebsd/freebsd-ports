# Created by: Cheng-Lung Sung <clsung@FreeBSD.org>
# $FreeBSD$

PORTNAME=	django-pipeline
PORTVERSION=	1.6.6
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Asset (css/js) packaging library for Django

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django18>0:www/py-django18

NO_ARCH=	yes
USES=		python:2
USE_PYTHON=	autoplist distutils

CONFLICTS=	py[23][0-9]-django-pipeline12-[0-9]* \
		py[23][0-9]-django-pipeline13-[0-9]* \
		py[23][0-9]-django-pipeline14-[0-9]*

.include <bsd.port.mk>
