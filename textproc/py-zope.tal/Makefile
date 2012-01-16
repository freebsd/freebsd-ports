# New ports collection makefile for:	py-zope.tal
# Date created:				Nov 11, 2011
# Whom:					Ruslan Mahmatkhanov <cvs-src@yandex.ru>
#
# $FreeBSD$
#

PORTNAME=	zope.tal
PORTVERSION=	3.6.0
CATEGORIES=	textproc python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	zope@FreeBSD.org
COMMENT=	Zope Template Application Languate (TAL)

LICENSE=	ZPL21

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}zope.i18nmessageid>=0:${PORTSDIR}/textproc/py-zope.i18nmessageid \
		${PYTHON_PKGNAMEPREFIX}zope.interface>=0:${PORTSDIR}/devel/py-zope.interface \
		${PYTHON_PKGNAMEPREFIX}zope.testing>=0:${PORTSDIR}/devel/py-zope.testing

USE_PYTHON	=yes
USE_PYDISTUTILS=easy_install
USE_ZIP=	yes

.include <bsd.port.mk>
