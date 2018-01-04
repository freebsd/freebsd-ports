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

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}plone.alterego>0:www/py-plone.alterego@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}plone.autoform>0:www/py-plone.autoform@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}plone.behavior>0:www/py-plone.behavior@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}plone.folder>0:www/py-plone.folder@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}plone.memoize>0:www/py-plone.memoize@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}plone.rfc822>0:www/py-plone.rfc822@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}plone.supermodel>0:www/py-plone.supermodel@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}plone.synchronize>0:www/py-plone.synchronize@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}plone.uuid>0:www/py-plone.uuid@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}plone.z3cform>0:www/py-plone.z3cform@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Products.CMFCore>0:devel/py-Products.CMFCore@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Products.CMFDefault>0:devel/py-Products.CMFDefault@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Products.CMFDynamicViewFTI>0:devel/py-Products.CMFDynamicViewFTI@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Products.statusmessages>0:devel/py-Products.statusmessages@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.annotation>0:devel/py-zope.annotation@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.browser>0:devel/py-zope.browser@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.component>0:devel/py-zope.component@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.container>0:devel/py-zope.container@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.dottedname>0:devel/py-zope.dottedname@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.interface>0:devel/py-zope.interface@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.lifecycleevent>0:devel/py-zope.lifecycleevent@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.location>0:devel/py-zope.location@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.publisher>0:devel/py-zope.publisher@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.schema>0:devel/py-zope.schema@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.security>0:security/py-zope.security@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.filerepresentation>0:devel/py-zope.filerepresentation@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.size>0:devel/py-zope.size@${FLAVOR} \
		zodb${PYTHON_PKGNAMESUFFIX}>0:databases/zodb3@${FLAVOR}

NO_ARCH=	yes
USES=		python:2.7 zope
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
