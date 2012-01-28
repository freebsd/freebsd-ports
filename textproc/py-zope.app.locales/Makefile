# New ports collection makefile for:	py-zope.app.locales
# Date created:				23 December 2011
# Whom:					Ruslan Mahmatkhanov <cvs-src@yandex.ru>
#
# $FreeBSD$
#

PORTNAME=	zope.app.locales
PORTVERSION=	3.7.3
CATEGORIES=	textproc python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	zope@FreeBSD.org
COMMENT=	Zope locale extraction and management utilities

LICENSE=	ZPL21

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}zope.i18n>=0:${PORTSDIR}/devel/py-zope.i18n \
		${PYTHON_PKGNAMEPREFIX}zope.configuration>=0:${PORTSDIR}/devel/py-zope.configuration \
		${PYTHON_PKGNAMEPREFIX}zope.tal>=0:${PORTSDIR}/textproc/py-zope.tal \
		${PYTHON_PKGNAMEPREFIX}zope.app.applicationcontrol>=0:${PORTSDIR}/devel/py-zope.app.applicationcontrol \
		${PYTHON_PKGNAMEPREFIX}zope.app.appsetup>=0:${PORTSDIR}/devel/py-zope.app.appsetup

DIST_SUBDIR=	zope
USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install

.include <bsd.port.mk>
