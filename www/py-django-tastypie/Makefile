# New ports collection makefile for:	django-tastypie
# Date created:			May 8, 2012
# Whom:				William Grzybowski
#
# $FreeBSD$
#

PORTNAME=	django-tastypie
PORTVERSION=	0.9.11
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	william88@gmail.com
COMMENT=	Create REST API for Django apps

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dateutil>=1.5:${PORTSDIR}/devel/py-dateutil

USE_PYTHON=	2.5+
USE_PYDISTUTILS=	easy_install
PYDISTUTILS_NOEGGINFO=	yes

PLIST_FILES=	%%PYTHON_SITELIBDIR%%/%%PYEASYINSTALL_EGG%%

.include <bsd.port.mk>
