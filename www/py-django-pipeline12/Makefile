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

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django14>0:${PORTSDIR}/www/py-django14

CONFLICTS=	py[23][0-9]-django-pipeline-[0-9]*

USE_PYTHON=	2
USE_PYDISTUTILS=yes

.include <bsd.port.mk>
