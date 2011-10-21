# New ports collection makefile for:	py-django-pipeline
# Date created:				2011-09-27
# Whom:					Cheng-Lung Sung <clsung@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	django-pipeline
PORTVERSION=	1.1.19
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Pipeline is an asset (css/js) packaging library for Django

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/django/bin/django-admin.py:${PORTSDIR}/www/py-django

USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install

.include <bsd.port.mk>
