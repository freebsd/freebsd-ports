# $FreeBSD$

PORTNAME=	plone.app.contentmenu
PORTVERSION=	2.0.11
CATEGORIES=	www python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	zope

MAINTAINER=	zope@FreeBSD.org
COMMENT=	Plone's content menu implementation

LICENSE=	GPLv2

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}plone.locking>=0:www/py-plone.locking \
		${PYTHON_PKGNAMEPREFIX}plone.memoize>=0:www/py-plone.memoize \
		${PYTHON_PKGNAMEPREFIX}plone.app.content>=2.0:www/py-plone.app.content \
		${PYTHON_PKGNAMEPREFIX}zope.browsermenu>0:devel/py-zope.browsermenu \
		${PYTHON_PKGNAMEPREFIX}zope.component>=0:devel/py-zope.component \
		${PYTHON_PKGNAMEPREFIX}zope.contentprovider>=0:devel/py-zope.contentprovider \
		${PYTHON_PKGNAMEPREFIX}zope.interface>=0:devel/py-zope.interface \
		${PYTHON_PKGNAMEPREFIX}zope.i18n>=0:devel/py-zope.i18n \
		${PYTHON_PKGNAMEPREFIX}zope.i18nmessageid>=0:textproc/py-zope.i18nmessageid \
		${PYTHON_PKGNAMEPREFIX}zope.publisher>=0:devel/py-zope.publisher \
		${PYTHON_PKGNAMEPREFIX}zope.app.publisher>=0:devel/py-zope.app.publisher \
		${PYTHON_PKGNAMEPREFIX}Acquisition>=0:devel/py-Acquisition \
		${PYTHON_PKGNAMEPREFIX}Products.CMFCore>=0:devel/py-Products.CMFCore \
		${PYTHON_PKGNAMEPREFIX}Products.CMFDynamicViewFTI>=0:devel/py-Products.CMFDynamicViewFTI

NO_ARCH=	yes
USES=		python zope
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
