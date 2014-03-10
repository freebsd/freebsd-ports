# $FreeBSD$

PORTNAME=	AccessControl
PORTVERSION=	3.0.8
PORTREVISION=	1
CATEGORIES=	security python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	zope

MAINTAINER=	zope@FreeBSD.org
COMMENT=	Security framework for Zope2

LICENSE=	ZPL21

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Acquisition>=0:${PORTSDIR}/devel/py-Acquisition \
		${PYTHON_PKGNAMEPREFIX}DateTime>=0:${PORTSDIR}/devel/py-DateTime \
		${PYTHON_PKGNAMEPREFIX}ExtensionClass>=0:${PORTSDIR}/devel/py-ExtensionClass \
		${PYTHON_PKGNAMEPREFIX}Persistence>=0:${PORTSDIR}/devel/py-Persistence \
		${PYTHON_PKGNAMEPREFIX}Record>=0:${PORTSDIR}/devel/py-Record \
		${PYTHON_PKGNAMEPREFIX}RestrictedPython>=0:${PORTSDIR}/security/py-RestrictedPython \
		${PYTHON_PKGNAMEPREFIX}transaction>=0:${PORTSDIR}/devel/py-transaction \
		${PYTHON_PKGNAMEPREFIX}zExceptions>=0:${PORTSDIR}/devel/py-zExceptions \
		zodb${PYTHON_PKGNAMESUFFIX}>=0:${PORTSDIR}/databases/zodb3 \
		${PYTHON_PKGNAMEPREFIX}zope.component>=0:${PORTSDIR}/devel/py-zope.component \
		${PYTHON_PKGNAMEPREFIX}zope.configuration>=0:${PORTSDIR}/devel/py-zope.configuration \
		${PYTHON_PKGNAMEPREFIX}zope.deferredimport>=0:${PORTSDIR}/devel/py-zope.deferredimport \
		${PYTHON_PKGNAMEPREFIX}zope.interface>=0:${PORTSDIR}/devel/py-zope.interface \
		${PYTHON_PKGNAMEPREFIX}zope.publisher>=0:${PORTSDIR}/devel/py-zope.publisher \
		${PYTHON_PKGNAMEPREFIX}zope.schema>=0:${PORTSDIR}/devel/py-zope.schema \
		${PYTHON_PKGNAMEPREFIX}zope.security>=0:${PORTSDIR}/security/py-zope.security \
		${PYTHON_PKGNAMEPREFIX}zope.testing>=0:${PORTSDIR}/devel/py-zope.testing

USES=		zip
USE_PYTHON=		2
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

.include <bsd.port.mk>
