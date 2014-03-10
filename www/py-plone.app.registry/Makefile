# $FreeBSD$

PORTNAME=	plone.app.registry
PORTVERSION=	1.2.3
PORTREVISION=	1
CATEGORIES=	www python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	zope

MAINTAINER=	zope@FreeBSD.org
COMMENT=	Zope 2 and Plone integration for plone.registry

LICENSE=	GPLv2

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}plone.registry>=1.0:${PORTSDIR}/www/py-plone.registry \
		${PYTHON_PKGNAMEPREFIX}plone.supermodel>=1.1:${PORTSDIR}/www/py-plone.supermodel \
		${PYTHON_PKGNAMEPREFIX}plone.app.z3cform>=0:${PORTSDIR}/www/py-plone.app.z3cform \
		${PYTHON_PKGNAMEPREFIX}plone.autoform>=1.0:${PORTSDIR}/www/py-plone.autoform \
		${PYTHON_PKGNAMEPREFIX}Products.CMFCore>=0:${PORTSDIR}/devel/py-Products.CMFCore \
		${PYTHON_PKGNAMEPREFIX}Products.GenericSetup>=0:${PORTSDIR}/devel/py-Products.GenericSetup \
		${PYTHON_PKGNAMEPREFIX}Products.statusmessages>=0:${PORTSDIR}/devel/py-Products.statusmessages \
		${PYTHON_PKGNAMEPREFIX}lxml>0:${PORTSDIR}/devel/py-lxml \
		${PYTHON_PKGNAMEPREFIX}zope.component>=0:${PORTSDIR}/devel/py-zope.component \
		${PYTHON_PKGNAMEPREFIX}zope.interface>=0:${PORTSDIR}/devel/py-zope.interface \
		${PYTHON_PKGNAMEPREFIX}zope.i18nmessageid>=0:${PORTSDIR}/textproc/py-zope.i18nmessageid \
		${PYTHON_PKGNAMEPREFIX}zope.dottedname>=0:${PORTSDIR}/devel/py-zope.dottedname

USE_PYTHON=		2
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes
USES=			zope zip

.include <bsd.port.mk>
