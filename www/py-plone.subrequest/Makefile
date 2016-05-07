# $FreeBSD$

PORTNAME=	plone.subrequest
PORTVERSION=	1.6.11
CATEGORIES=	www python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	zope

MAINTAINER=	zope@FreeBSD.org
COMMENT=	Subrequests for Zope2

LICENSE=	GPLv2

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}five.globalrequest>=0:devel/py-five.globalrequest \
		${PYTHON_PKGNAMEPREFIX}zope.globalrequest>=0:devel/py-zope.globalrequest

NO_ARCH=	yes
USES=		python
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
