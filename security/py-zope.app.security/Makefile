# $FreeBSD$

PORTNAME=	zope.app.security
PORTVERSION=	3.7.5
PORTREVISION=	1
CATEGORIES=	security python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	zope

MAINTAINER=	zope@FreeBSD.org
COMMENT=	ZMI Views For Zope3 Security Components

LICENSE=	ZPL21

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}zope.app.localpermission>=0:security/py-zope.app.localpermission \
		${PYTHON_PKGNAMEPREFIX}zope.app.pagetemplate>=0:devel/py-zope.app.pagetemplate \
		${PYTHON_PKGNAMEPREFIX}zope.app.publisher>=0:devel/py-zope.app.publisher \
		${PYTHON_PKGNAMEPREFIX}zope.authentication>=0:security/py-zope.authentication \
		${PYTHON_PKGNAMEPREFIX}zope.i18n>=0:devel/py-zope.i18n \
		${PYTHON_PKGNAMEPREFIX}zope.i18nmessageid>=0:textproc/py-zope.i18nmessageid \
		${PYTHON_PKGNAMEPREFIX}zope.interface>=0:devel/py-zope.interface \
		${PYTHON_PKGNAMEPREFIX}zope.principalregistry>=0:security/py-zope.principalregistry \
		${PYTHON_PKGNAMEPREFIX}zope.publisher>=3.12:devel/py-zope.publisher \
		${PYTHON_PKGNAMEPREFIX}zope.security>=0:security/py-zope.security \
		${PYTHON_PKGNAMEPREFIX}zope.securitypolicy>=0:security/py-zope.securitypolicy \
		${PYTHON_PKGNAMEPREFIX}zope.login>=0:security/py-zope.login

USES=		python
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
