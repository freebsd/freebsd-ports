# $FreeBSD$

PORTNAME=	Products.TinyMCE
PORTVERSION=	1.3.5
PORTREVISION=	1
CATEGORIES=	www python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	zope

MAINTAINER=	zope@FreeBSD.org
COMMENT=	Adds support for TinyMCE to Plone

LICENSE=	LGPL21

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}plone.app.imaging>=1.0.2:${PORTSDIR}/www/py-plone.app.imaging \
		${PYTHON_PKGNAMEPREFIX}plone.outputfilters>=0:${PORTSDIR}/www/py-plone.outputfilters \
		${PYTHON_PKGNAMEPREFIX}plone.namedfile>0:${PORTSDIR}/www/py-plone.namedfile \
		${PYTHON_PKGNAMEPREFIX}plone.app.layout>0:${PORTSDIR}/www/py-plone.app.layout \
		${PYTHON_PKGNAMEPREFIX}plone.caching>0:${PORTSDIR}/www/py-plone.caching \
		${PYTHON_PKGNAMEPREFIX}Products.ResourceRegistries>0:${PORTSDIR}/devel/py-Products.ResourceRegistries \
		${PYTHON_PKGNAMEPREFIX}zope.app.content>0:${PORTSDIR}/devel/py-zope.app.content \
		${PYTHON_PKGNAMEPREFIX}zope.schema>0:${PORTSDIR}/devel/py-zope.schema

USES=		zip
USE_PYTHON=		2
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

.include <bsd.port.mk>
