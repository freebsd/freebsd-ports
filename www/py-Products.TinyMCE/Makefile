# $FreeBSD$

PORTNAME=	Products.TinyMCE
PORTVERSION=	1.3.19
CATEGORIES=	www python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	zope

MAINTAINER=	zope@FreeBSD.org
COMMENT=	Adds support for TinyMCE to Plone

LICENSE=	LGPL21

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}plone.app.imaging>=1.0.2:www/py-plone.app.imaging \
		${PYTHON_PKGNAMEPREFIX}plone.outputfilters>=0:www/py-plone.outputfilters \
		${PYTHON_PKGNAMEPREFIX}plone.namedfile>0:www/py-plone.namedfile \
		${PYTHON_PKGNAMEPREFIX}plone.app.layout>0:www/py-plone.app.layout \
		${PYTHON_PKGNAMEPREFIX}plone.caching>0:www/py-plone.caching \
		${PYTHON_PKGNAMEPREFIX}Products.ResourceRegistries>0:devel/py-Products.ResourceRegistries \
		${PYTHON_PKGNAMEPREFIX}zope.app.content>0:devel/py-zope.app.content \
		${PYTHON_PKGNAMEPREFIX}zope.schema>0:devel/py-zope.schema

NO_ARCH=	yes
USES=		python:2.7 zip
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
