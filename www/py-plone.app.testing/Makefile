# $FreeBSD$

PORTNAME=	plone.app.testing
PORTVERSION=	4.2.2
CATEGORIES=	www python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	zope@FreeBSD.org
COMMENT=	Testing tools for Plone-the-application, based on plone.testing

LICENSE=	GPLv2

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}zope.configuration>=0:${PORTSDIR}/devel/py-zope.configuration \
		${PYTHON_PKGNAMEPREFIX}zope.component>=0:${PORTSDIR}/devel/py-zope.component \
		${PYTHON_PKGNAMEPREFIX}zope.dottedname>=0:${PORTSDIR}/devel/py-zope.dottedname \
		${PYTHON_PKGNAMEPREFIX}zope.site>=0:${PORTSDIR}/devel/py-zope.site \
		${PYTHON_PKGNAMEPREFIX}zope.testing>=0:${PORTSDIR}/devel/py-zope.testing \
		${PYTHON_PKGNAMEPREFIX}five.localsitemanager>=0:${PORTSDIR}/devel/py-five.localsitemanager \
		${PYTHON_PKGNAMEPREFIX}plone.memoize>=0:${PORTSDIR}/www/py-plone.memoize \
		${PYTHON_PKGNAMEPREFIX}plone.testing>=0:${PORTSDIR}/www/py-plone.testing \
		${PYTHON_PKGNAMEPREFIX}Products.GenericSetup>=0:${PORTSDIR}/devel/py-Products.GenericSetup

DIST_SUBDIR=	zope
USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install
USE_ZIP=	yes
USE_ZOPE=	yes

NO_STAGE=	yes
.include <bsd.port.mk>
