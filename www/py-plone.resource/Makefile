# $FreeBSD$

PORTNAME=	plone.resource
PORTVERSION=	1.0.2
PORTEPOCH=	1
CATEGORIES=	www python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	zope@FreeBSD.org
COMMENT=	Publishes directories of static files via the ZPublisher

LICENSE=	GPLv2

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}zope.interface>=0:${PORTSDIR}/devel/py-zope.interface \
		${PYTHON_PKGNAMEPREFIX}zope.component>=0:${PORTSDIR}/devel/py-zope.component \
		${PYTHON_PKGNAMEPREFIX}zope.traversing>=0:${PORTSDIR}/devel/py-zope.traversing \
		${PYTHON_PKGNAMEPREFIX}zope.publisher>=0:${PORTSDIR}/devel/py-zope.publisher \
		${PYTHON_PKGNAMEPREFIX}zope.configuration>=0:${PORTSDIR}/devel/py-zope.configuration \
		${PYTHON_PKGNAMEPREFIX}zope.schema>=0:${PORTSDIR}/devel/py-zope.schema \
		${PYTHON_PKGNAMEPREFIX}zope.filerepresentation>=0:${PORTSDIR}/devel/py-zope.filerepresentation \
		${PYTHON_PKGNAMEPREFIX}z3c.caching>=0:${PORTSDIR}/devel/py-z3c.caching \
		${PYTHON_PKGNAMEPREFIX}dateutil>=0:${PORTSDIR}/devel/py-dateutil \
		${PYTHON_PKGNAMEPREFIX}plone.caching>=0:${PORTSDIR}/www/py-plone.caching

DIST_SUBDIR=	zope
USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install
USE_ZIP=	yes
USE_ZOPE=	yes

NO_STAGE=	yes
.include <bsd.port.mk>
