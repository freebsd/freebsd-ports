# $FreeBSD$

PORTNAME=	plone.caching
PORTVERSION=	1.0.1
CATEGORIES=	www python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	zope

MAINTAINER=	zope@FreeBSD.org
COMMENT=	Zope 2 integration for z3c.caching

LICENSE=	GPLv2

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}z3c.caching>=0:${PORTSDIR}/devel/py-z3c.caching \
		${PYTHON_PKGNAMEPREFIX}plone.registry>=0:${PORTSDIR}/www/py-plone.registry \
		${PYTHON_PKGNAMEPREFIX}zope.interface>=0:${PORTSDIR}/devel/py-zope.interface \
		${PYTHON_PKGNAMEPREFIX}zope.component>=0:${PORTSDIR}/devel/py-zope.component \
		${PYTHON_PKGNAMEPREFIX}zope.i18nmessageid>=0:${PORTSDIR}/textproc/py-zope.i18nmessageid \
		${PYTHON_PKGNAMEPREFIX}zope.schema>=0:${PORTSDIR}/devel/py-zope.schema \
		${PYTHON_PKGNAMEPREFIX}plone.transformchain>=0:${PORTSDIR}/www/py-plone.transformchain \
		${PYTHON_PKGNAMEPREFIX}five.globalrequest>=0:${PORTSDIR}/devel/py-five.globalrequest

NO_ARCH=	yes
USES=		python zip
USE_PYTHON=	autoplist distutils
#USES=		zope

.include <bsd.port.mk>
