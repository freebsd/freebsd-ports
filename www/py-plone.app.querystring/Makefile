# $FreeBSD$

PORTNAME=	plone.app.querystring
PORTVERSION=	1.2.9
CATEGORIES=	www python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	zope

MAINTAINER=	zope@FreeBSD.org
COMMENT=	Tools to parse stored queries to actual results

LICENSE=	GPLv2

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}DateTime>=0:devel/py-DateTime \
		${PYTHON_PKGNAMEPREFIX}Products.CMFCore>=0:devel/py-Products.CMFCore \
		${PYTHON_PKGNAMEPREFIX}plone.app.contentlisting>=0:www/py-plone.app.contentlisting \
		${PYTHON_PKGNAMEPREFIX}plone.app.layout>=0:www/py-plone.app.layout \
		${PYTHON_PKGNAMEPREFIX}plone.app.registry>=1.1:www/py-plone.app.registry \
		${PYTHON_PKGNAMEPREFIX}plone.app.vocabularies>=0:www/py-plone.app.vocabularies \
		${PYTHON_PKGNAMEPREFIX}plone.batching>0:www/py-plone.batching \
		${PYTHON_PKGNAMEPREFIX}plone.registry>0:www/py-plone.registry \
		${PYTHON_PKGNAMEPREFIX}zope.component>0:devel/py-zope.component \
		${PYTHON_PKGNAMEPREFIX}zope.dottedname>0:devel/py-zope.dottedname \
		${PYTHON_PKGNAMEPREFIX}zope.globalrequest>0:devel/py-zope.globalrequest \
		${PYTHON_PKGNAMEPREFIX}zope.i18n>0:devel/py-zope.i18n \
		${PYTHON_PKGNAMEPREFIX}zope.i18nmessageid>0:textproc/py-zope.i18nmessageid \
		${PYTHON_PKGNAMEPREFIX}zope.interface>0:devel/py-zope.interface \
		${PYTHON_PKGNAMEPREFIX}zope.publisher>0:devel/py-zope.publisher \
		${PYTHON_PKGNAMEPREFIX}zope.schema>0:devel/py-zope.schema

NO_ARCH=	yes
USES=		python
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
