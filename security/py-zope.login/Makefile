# $FreeBSD$

PORTNAME=	zope.login
PORTVERSION=	1.0.0
PORTREVISION=	1
CATEGORIES=	security python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	zope

MAINTAINER=	zope@FreeBSD.org
COMMENT=	Login helpers for zope.publisher / authentication

LICENSE=	ZPL21

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}zope.authentication>=0:security/py-zope.authentication \
		${PYTHON_PKGNAMEPREFIX}zope.component>=0:devel/py-zope.component \
		${PYTHON_PKGNAMEPREFIX}zope.interface>=0:devel/py-zope.interface \
		${PYTHON_PKGNAMEPREFIX}zope.publisher>=0:devel/py-zope.publisher

USES=		python zip
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
