# New ports collection makefile for:	py-Products.TinyMCE
# Date created:				03 January 2012
# Whom:					Ruslan Mahmatkhanov <cvs-src@yandex.ru>
#
# $FreeBSD$
#

PORTNAME=	Products.TinyMCE
PORTVERSION=	1.2.9
CATEGORIES=	www python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	zope@FreeBSD.org
COMMENT=	Adds support for TinyMCE to Plone

LICENSE=	LGPL21

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}plone.app.imaging>=1.0.2:${PORTSDIR}/www/py-plone.app.imaging \
		${PYTHON_PKGNAMEPREFIX}plone.outputfilters>=0:${PORTSDIR}/www/py-plone.outputfilters \
		${PYTHON_PKGNAMEPREFIX}elementtree>=0:${PORTSDIR}/devel/py-elementtree

DIST_SUBDIR=	zope
USE_PYTHON=	2.6+
USE_PYDISTUTILS=	easy_install
USE_ZIP=	yes

.include <bsd.port.mk>
