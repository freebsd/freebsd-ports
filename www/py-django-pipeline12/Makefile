# Created by: Cheng-Lung Sung <clsung@FreeBSD.org>
# $FreeBSD$

PORTNAME=	django-pipeline
PORTVERSION=	1.2.24
PORTEPOCH=	1
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX=	12

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Asset (css/js) packaging library for Django

DEPRECATED=	Django 1.4 extended support ended on 2015-10-01
EXPIRATION_DATE=	2015-12-09

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django14>0:${PORTSDIR}/www/py-django14

CONFLICTS=	py[23][0-9]-django-pipeline-[0-9]* \
		py[23][0-9]-django-pipeline13-[0-9]* \
		py[23][0-9]-django-pipeline14-[0-9]*

USES=		python:2
USE_PYTHON=	distutils

.include <bsd.port.mk>
