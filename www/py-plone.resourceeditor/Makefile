# $FreeBSD$

PORTNAME=	plone.resourceeditor
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	www python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	zope

MAINTAINER=	zope@FreeBSD.org
COMMENT=	Resources for integrating ACE into Plone

LICENSE=	GPLv2

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}zope.interface>0:devel/py-zope.interface \
		${PYTHON_PKGNAMEPREFIX}zope.component>0:devel/py-zope.component \
		${PYTHON_PKGNAMEPREFIX}zope.publisher>0:devel/py-zope.publisher \
		${PYTHON_PKGNAMEPREFIX}zope.schema>0:devel/py-zope.schema \
		${PYTHON_PKGNAMEPREFIX}plone.resource>0:www/py-plone.resource

NO_ARCH=	yes
USES=		python:2.7 zip
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
