# $FreeBSD$

PORTNAME=	Products.kupu
PORTVERSION=	1.5.1
CATEGORIES=	www python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	zope@FreeBSD.org
COMMENT=	Cross-browser WYWSIWYG editor

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}plone.outputfilters>=0:${PORTSDIR}/www/py-plone.outputfilters \
		${PYTHON_PKGNAMEPREFIX}zope.interface>=0:${PORTSDIR}/devel/py-zope.interface \
		${PYTHON_PKGNAMEPREFIX}zope.schema>=0:${PORTSDIR}/devel/py-zope.schema \
		${PYTHON_PKGNAMEPREFIX}zope.i18n>=0:${PORTSDIR}/devel/py-zope.i18n \
		${PYTHON_PKGNAMEPREFIX}zope.i18nmessageid>=0:${PORTSDIR}/textproc/py-zope.i18nmessageid \
		${PYTHON_PKGNAMEPREFIX}Products.Archetypes>=0:${PORTSDIR}/devel/py-Products.Archetypes \
		${PYTHON_PKGNAMEPREFIX}Products.GenericSetup>=0:${PORTSDIR}/devel/py-Products.GenericSetup \
		${PYTHON_PKGNAMEPREFIX}Products.CMFCore>=0:${PORTSDIR}/devel/py-Products.CMFCore \
		${PYTHON_PKGNAMEPREFIX}Products.CMFPlone>=4.1:${PORTSDIR}/www/py-Products.CMFPlone \
		${PYTHON_PKGNAMEPREFIX}Products.MimetypesRegistry>=0:${PORTSDIR}/devel/py-Products.MimetypesRegistry \
		${PYTHON_PKGNAMEPREFIX}Products.PortalTransforms>=0:${PORTSDIR}/devel/py-Products.PortalTransforms \
		${PYTHON_PKGNAMEPREFIX}zope.app.component>0:${PORTSDIR}/devel/py-zope.app.component

DIST_SUBDIR=	zope
USE_PYTHON=	-2.7
USE_PYDISTUTILS=easy_install
USE_ZIP=	yes

NO_STAGE=	yes
.include <bsd.port.mk>
