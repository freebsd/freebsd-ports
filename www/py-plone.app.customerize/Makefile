# $FreeBSD$

PORTNAME=	plone.app.customerize
PORTVERSION=	1.2.3
CATEGORIES=	www python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	zope

MAINTAINER=	zope@FreeBSD.org
COMMENT=	Integrate five.customerize into Plone

LICENSE=	GPLv2

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}five.customerize>=0:devel/py-five.customerize \
		${PYTHON_PKGNAMEPREFIX}plone.browserlayer>=0:www/py-plone.browserlayer \
		${PYTHON_PKGNAMEPREFIX}plone.portlets>=0:www/py-plone.portlets \
		${PYTHON_PKGNAMEPREFIX}zope.component>=0:devel/py-zope.component \
		${PYTHON_PKGNAMEPREFIX}zope.interface>=0:devel/py-zope.interface \
		${PYTHON_PKGNAMEPREFIX}zope.publisher>=0:devel/py-zope.publisher \
		${PYTHON_PKGNAMEPREFIX}zope.viewlet>=0:devel/py-zope.viewlet \
		${PYTHON_PKGNAMEPREFIX}Products.CMFCore>=0:devel/py-Products.CMFCore \
		${PYTHON_PKGNAMEPREFIX}Acquisition>=0:devel/py-Acquisition

NO_ARCH=	yes
USES=		python
USE_PYTHON=	autoplist distutils
#USES=		zope

.include <bsd.port.mk>
