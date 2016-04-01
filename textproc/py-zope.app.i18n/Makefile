# $FreeBSD$

PORTNAME=	zope.app.i18n
PORTVERSION=	3.6.4
PORTREVISION=	1
CATEGORIES=	textproc python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	zope

MAINTAINER=	zope@FreeBSD.org
COMMENT=	Persistent translation domains and message catalogs

LICENSE=	ZPL21

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}zope.publisher>=3.9:devel/py-zope.publisher \
		${PYTHON_PKGNAMEPREFIX}zope.component>=3.6:devel/py-zope.component \
		${PYTHON_PKGNAMEPREFIX}zope.container>=0:devel/py-zope.container \
		${PYTHON_PKGNAMEPREFIX}zope.configuration>=0:devel/py-zope.configuration \
		${PYTHON_PKGNAMEPREFIX}zope.i18n>=0:devel/py-zope.i18n \
		${PYTHON_PKGNAMEPREFIX}zope.i18nmessageid>=0:textproc/py-zope.i18nmessageid \
		${PYTHON_PKGNAMEPREFIX}zope.interface>=0:devel/py-zope.interface \
		${PYTHON_PKGNAMEPREFIX}zope.security>=0:security/py-zope.security \
		zodb${PYTHON_PKGNAMESUFFIX}>=0:databases/zodb3

USES=		python
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
