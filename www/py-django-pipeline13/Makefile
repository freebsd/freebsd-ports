# Created by: Cheng-Lung Sung <clsung@FreeBSD.org>
# $FreeBSD$

PORTNAME=	django-pipeline
PORTVERSION=	1.3.27
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX=	13

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Asset (css/js) packaging library for Django

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django16>0:${PORTSDIR}/www/py-django16

NO_ARCH=	yes
USES=		python:2
USE_PYTHON=	autoplist distutils

CONFLICTS=	py[23][0-9]-django-pipeline-[0-9]* \
		py[23][0-9]-django-pipeline12-[0-9]* \
		py[23][0-9]-django-pipeline13-[0-9]*

.include <bsd.port.mk>
