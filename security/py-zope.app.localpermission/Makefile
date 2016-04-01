# $FreeBSD$

PORTNAME=	zope.app.localpermission
PORTVERSION=	3.7.2
PORTREVISION=	1
CATEGORIES=	security python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	zope

MAINTAINER=	zope@FreeBSD.org
COMMENT=	Local Persistent Permissions for zope.security

LICENSE=	ZPL21

RUN_DEPENDS=	zodb${PYTHON_PKGNAMESUFFIX}>=0:databases/zodb3 \
		${PYTHON_PKGNAMEPREFIX}zope.component>=0:devel/py-zope.component \
		${PYTHON_PKGNAMEPREFIX}zope.i18nmessageid>=0:textproc/py-zope.i18nmessageid \
		${PYTHON_PKGNAMEPREFIX}zope.interface>=0:devel/py-zope.interface \
		${PYTHON_PKGNAMEPREFIX}zope.location>=0:devel/py-zope.location \
		${PYTHON_PKGNAMEPREFIX}zope.security>=0:security/py-zope.security

USES=		python
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
