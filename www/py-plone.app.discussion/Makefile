# $FreeBSD$

PORTNAME=	plone.app.discussion
PORTVERSION=	2.2.16
CATEGORIES=	www python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	zope

MAINTAINER=	zope@FreeBSD.org
COMMENT=	Enhanced discussion support for Plone

LICENSE=	GPLv2

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}collective.monkeypatcher>=0:devel/py-collective.monkeypatcher \
		${PYTHON_PKGNAMEPREFIX}plone.app.layout>=0:www/py-plone.app.layout \
		${PYTHON_PKGNAMEPREFIX}plone.app.registry>=0:www/py-plone.app.registry \
		${PYTHON_PKGNAMEPREFIX}plone.app.uuid>=0:www/py-plone.app.uuid \
		${PYTHON_PKGNAMEPREFIX}plone.app.z3cform>=0:www/py-plone.app.z3cform \
		${PYTHON_PKGNAMEPREFIX}plone.indexer>=0:www/py-plone.indexer \
		${PYTHON_PKGNAMEPREFIX}plone.registry>=0:www/py-plone.registry \
		${PYTHON_PKGNAMEPREFIX}plone.z3cform>=0:www/py-plone.z3cform \
		zodb${PYTHON_PKGNAMESUFFIX}>=0:databases/zodb3 \
		${PYTHON_PKGNAMEPREFIX}zope.interface>=0:devel/py-zope.interface \
		${PYTHON_PKGNAMEPREFIX}zope.component>=0:devel/py-zope.component \
		${PYTHON_PKGNAMEPREFIX}zope.annotation>=0:devel/py-zope.annotation \
		${PYTHON_PKGNAMEPREFIX}zope.event>=0:devel/py-zope.event \
		${PYTHON_PKGNAMEPREFIX}zope.container>=0:devel/py-zope.container \
		${PYTHON_PKGNAMEPREFIX}zope.lifecycleevent>=0:devel/py-zope.lifecycleevent \
		${PYTHON_PKGNAMEPREFIX}zope.site>=0:devel/py-zope.site \
		${PYTHON_PKGNAMEPREFIX}z3c.form>=2.3.3:devel/py-z3c.form

NO_ARCH=	yes
USES=		python:2.7
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
