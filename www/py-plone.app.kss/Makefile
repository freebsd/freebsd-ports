# $FreeBSD$

PORTNAME=	plone.app.kss
PORTVERSION=	1.7.1
CATEGORIES=	www python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	zope@FreeBSD.org
COMMENT=	KSS (Kinetic Style Sheets) for Plone

LICENSE=	GPLv2

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}kss-core>=0:${PORTSDIR}/devel/py-kss-core \
		${PYTHON_PKGNAMEPREFIX}plone.portlets>=2.0.1:${PORTSDIR}/www/py-plone.portlets \
		${PYTHON_PKGNAMEPREFIX}plone.app.layout>=0:${PORTSDIR}/www/py-plone.app.layout \
		${PYTHON_PKGNAMEPREFIX}plone.app.portlets>=0:${PORTSDIR}/www/py-plone.app.portlets \
		${PYTHON_PKGNAMEPREFIX}plone.locking>=0:${PORTSDIR}/www/py-plone.locking \
		${PYTHON_PKGNAMEPREFIX}zope.component>=0:${PORTSDIR}/devel/py-zope.component \
		${PYTHON_PKGNAMEPREFIX}zope.contentprovider>=0:${PORTSDIR}/devel/py-zope.contentprovider \
		${PYTHON_PKGNAMEPREFIX}zope.deprecation>=0:${PORTSDIR}/devel/py-zope.deprecation \
		${PYTHON_PKGNAMEPREFIX}zope.i18n>=0:${PORTSDIR}/devel/py-zope.i18n \
		${PYTHON_PKGNAMEPREFIX}zope.i18nmessageid>=0:${PORTSDIR}/textproc/py-zope.i18nmessageid \
		${PYTHON_PKGNAMEPREFIX}zope.interface>=0:${PORTSDIR}/devel/py-zope.interface \
		${PYTHON_PKGNAMEPREFIX}zope.lifecycleevent>=0:${PORTSDIR}/devel/py-zope.lifecycleevent \
		${PYTHON_PKGNAMEPREFIX}zope.viewlet>=0:${PORTSDIR}/devel/py-zope.viewlet \
		${PYTHON_PKGNAMEPREFIX}Acquisition>=0:${PORTSDIR}/devel/py-Acquisition \
		${PYTHON_PKGNAMEPREFIX}Products.CMFCore>=0:${PORTSDIR}/devel/py-Products.CMFCore \
		${PYTHON_PKGNAMEPREFIX}Products.DCWorkflow>=0:${PORTSDIR}/devel/py-Products.DCWorkflow \
		${PYTHON_PKGNAMEPREFIX}Products.statusmessages>=0:${PORTSDIR}/devel/py-Products.statusmessages

DIST_SUBDIR=	zope
USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install
USE_ZIP=	yes
USE_ZOPE=	yes

NO_STAGE=	yes
.include <bsd.port.mk>
