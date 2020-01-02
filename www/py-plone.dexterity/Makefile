# $FreeBSD$

PORTNAME=	plone.dexterity
PORTVERSION=	2.2.6
CATEGORIES=	www python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	zope

MAINTAINER=	zope@FreeBSD.org
COMMENT=	Flexible CMF content

DEPRECATED=	Outdated version of plone 4.3 (legacy), uses EOLed python27
EXPIRATION_DATE=	2020-02-03

LICENSE=	GPLv2

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}plone.alterego>0:www/py-plone.alterego@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}plone.autoform>0:www/py-plone.autoform@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}plone.behavior>0:www/py-plone.behavior@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}plone.folder>0:www/py-plone.folder@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}plone.memoize>0:www/py-plone.memoize@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}plone.rfc822>0:www/py-plone.rfc822@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}plone.supermodel>0:www/py-plone.supermodel@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}plone.synchronize>0:www/py-plone.synchronize@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}plone.uuid>0:www/py-plone.uuid@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}plone.z3cform>0:www/py-plone.z3cform@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Products.CMFCore>0:devel/py-Products.CMFCore@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Products.CMFDefault>0:devel/py-Products.CMFDefault@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Products.CMFDynamicViewFTI>0:devel/py-Products.CMFDynamicViewFTI@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Products.statusmessages>0:devel/py-Products.statusmessages@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.annotation>0:devel/py-zope.annotation@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.browser>0:devel/py-zope.browser@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.component>0:devel/py-zope.component@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.container>0:devel/py-zope.container@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.dottedname>0:devel/py-zope.dottedname@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.interface>0:devel/py-zope.interface@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.lifecycleevent>0:devel/py-zope.lifecycleevent@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.location>0:devel/py-zope.location@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.publisher>0:devel/py-zope.publisher@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.schema>0:devel/py-zope.schema@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.security>0:security/py-zope.security@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.filerepresentation>0:devel/py-zope.filerepresentation@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.size>0:devel/py-zope.size@${PY_FLAVOR} \
		zodb${PYTHON_PKGNAMESUFFIX}>0:databases/zodb3@${PY_FLAVOR}

NO_ARCH=	yes
USES=		python:2.7 zope
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
