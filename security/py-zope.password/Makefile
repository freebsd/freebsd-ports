# $FreeBSD$

PORTNAME=	zope.password
PORTVERSION=	3.6.1
PORTREVISION=	1
CATEGORIES=	security python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	zope

MAINTAINER=	zope@FreeBSD.org
COMMENT=	Password encoding and checking utilities

LICENSE=	ZPL21

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}zope.component>=0:devel/py-zope.component \
		${PYTHON_PKGNAMEPREFIX}zope.configuration>=0:devel/py-zope.configuration \
		${PYTHON_PKGNAMEPREFIX}zope.interface>=0:devel/py-zope.interface

USES=		python
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
