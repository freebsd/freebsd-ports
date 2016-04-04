# $FreeBSD$

PORTNAME=	zope.authentication
PORTVERSION=	3.7.1
PORTREVISION=	1
CATEGORIES=	security python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	zope

MAINTAINER=	zope@FreeBSD.org
COMMENT=	Definition of authentication basics for the Zope Framework

LICENSE=	ZPL21

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}zope.browser>=0:devel/py-zope.browser \
		${PYTHON_PKGNAMEPREFIX}zope.component>=3.6.0:devel/py-zope.component \
		${PYTHON_PKGNAMEPREFIX}zope.i18nmessageid>=0:textproc/py-zope.i18nmessageid \
		${PYTHON_PKGNAMEPREFIX}zope.interface>=0:devel/py-zope.interface \
		${PYTHON_PKGNAMEPREFIX}zope.schema>=0:devel/py-zope.schema \
		${PYTHON_PKGNAMEPREFIX}zope.security>=0:security/py-zope.security

USES=		python zip
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
