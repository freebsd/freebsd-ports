# $FreeBSD$

PORTNAME=	plone.dexterity
PORTVERSION=	2.2.6
CATEGORIES=	www python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	zope

MAINTAINER=	zope@FreeBSD.org
COMMENT=	Flexible CMF content

LICENSE=	GPLv2

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}plone.alterego>0:www/py-plone.alterego \
		${PYTHON_PKGNAMEPREFIX}plone.autoform>0:www/py-plone.autoform \
		${PYTHON_PKGNAMEPREFIX}plone.behavior>0:www/py-plone.behavior \
		${PYTHON_PKGNAMEPREFIX}plone.folder>0:www/py-plone.folder \
		${PYTHON_PKGNAMEPREFIX}plone.memoize>0:www/py-plone.memoize \
		${PYTHON_PKGNAMEPREFIX}plone.rfc822>0:www/py-plone.rfc822 \
		${PYTHON_PKGNAMEPREFIX}plone.supermodel>0:www/py-plone.supermodel \
		${PYTHON_PKGNAMEPREFIX}plone.synchronize>0:www/py-plone.synchronize \
		${PYTHON_PKGNAMEPREFIX}plone.uuid>0:www/py-plone.uuid \
		${PYTHON_PKGNAMEPREFIX}plone.z3cform>0:www/py-plone.z3cform \
		${PYTHON_PKGNAMEPREFIX}Products.CMFCore>0:devel/py-Products.CMFCore \
		${PYTHON_PKGNAMEPREFIX}Products.CMFDefault>0:devel/py-Products.CMFDefault \
		${PYTHON_PKGNAMEPREFIX}Products.CMFDynamicViewFTI>0:devel/py-Products.CMFDynamicViewFTI \
		${PYTHON_PKGNAMEPREFIX}Products.statusmessages>0:devel/py-Products.statusmessages \
		${PYTHON_PKGNAMEPREFIX}zope.annotation>0:devel/py-zope.annotation \
		${PYTHON_PKGNAMEPREFIX}zope.browser>0:devel/py-zope.browser \
		${PYTHON_PKGNAMEPREFIX}zope.component>0:devel/py-zope.component \
		${PYTHON_PKGNAMEPREFIX}zope.container>0:devel/py-zope.container \
		${PYTHON_PKGNAMEPREFIX}zope.dottedname>0:devel/py-zope.dottedname \
		${PYTHON_PKGNAMEPREFIX}zope.interface>0:devel/py-zope.interface \
		${PYTHON_PKGNAMEPREFIX}zope.lifecycleevent>0:devel/py-zope.lifecycleevent \
		${PYTHON_PKGNAMEPREFIX}zope.location>0:devel/py-zope.location \
		${PYTHON_PKGNAMEPREFIX}zope.publisher>0:devel/py-zope.publisher \
		${PYTHON_PKGNAMEPREFIX}zope.schema>0:devel/py-zope.schema \
		${PYTHON_PKGNAMEPREFIX}zope.security>0:security/py-zope.security \
		${PYTHON_PKGNAMEPREFIX}zope.filerepresentation>0:devel/py-zope.filerepresentation \
		${PYTHON_PKGNAMEPREFIX}zope.size>0:devel/py-zope.size \
		zodb${PYTHON_PKGNAMESUFFIX}>0:databases/zodb3

NO_ARCH=	yes
USES=		python:2.7 zope
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
