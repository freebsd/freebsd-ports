# $FreeBSD$

PORTNAME=	plone.app.imaging
PORTVERSION=	1.0.12
CATEGORIES=	www python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	zope

MAINTAINER=	zope@FreeBSD.org
COMMENT=	User-configurable, blob-aware image scaling for Plone

LICENSE=	GPLv2

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}plone.scale>0:www/py-plone.scale \
		${PYTHON_PKGNAMEPREFIX}z3c.caching>0:devel/py-z3c.caching

NO_ARCH=	yes
USES=		python
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
