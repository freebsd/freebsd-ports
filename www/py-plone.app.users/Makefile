# $FreeBSD$

PORTNAME=	plone.app.users
PORTVERSION=	1.2.4
CATEGORIES=	www python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	zope

MAINTAINER=	zope@FreeBSD.org
COMMENT=	Users and groups related things

LICENSE=	GPLv2

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}five.formlib>=0:devel/py-five.formlib@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}plone.protect>=0:security/py-plone.protect@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}plone.app.controlpanel>=2.1:www/py-plone.app.controlpanel@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}plone.app.layout>=0:www/py-plone.app.layout@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.component>=0:devel/py-zope.component@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.formlib>=0:devel/py-zope.formlib@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.i18nmessageid>=0:textproc/py-zope.i18nmessageid@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.interface>=0:devel/py-zope.interface@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.schema>=0:devel/py-zope.schema@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.site>=0:devel/py-zope.site@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Products.CMFCore>=0:devel/py-Products.CMFCore@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Products.PlonePAS>0:security/py-Products.PlonePAS@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Products.statusmessages>=0:devel/py-Products.statusmessages@${FLAVOR} \
		zodb${PYTHON_PKGNAMESUFFIX}>=0:databases/zodb3@${FLAVOR}

NO_ARCH=	yes
USES=		python:2.7
USE_PYTHON=	autoplist distutils
#USES=			zope

.include <bsd.port.mk>
