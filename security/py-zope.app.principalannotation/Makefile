# $FreeBSD$

PORTNAME=	zope.app.principalannotation
PORTVERSION=	3.7.0
PORTREVISION=	1
CATEGORIES=	security python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	zope

MAINTAINER=	zope@FreeBSD.org
COMMENT=	Bootstrap subscriber and browser menu item for zope.principalannotation

LICENSE=	ZPL21

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}transaction>=0:${PORTSDIR}/devel/py-transaction \
		${PYTHON_PKGNAMEPREFIX}zope.app.appsetup>=3.11.0:${PORTSDIR}/devel/py-zope.app.appsetup \
		${PYTHON_PKGNAMEPREFIX}zope.processlifetime>=0:${PORTSDIR}/devel/py-zope.processlifetime \
		${PYTHON_PKGNAMEPREFIX}zope.principalannotation>=0:${PORTSDIR}/security/py-zope.principalannotation

USES=		python
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
