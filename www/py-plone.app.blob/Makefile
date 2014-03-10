# $FreeBSD$

PORTNAME=	plone.app.blob
PORTVERSION=	1.5.8
PORTREVISION=	1
CATEGORIES=	www python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	zope

MAINTAINER=	zope@FreeBSD.org
COMMENT=	ZODB blob support for Plone

LICENSE=	GPLv2

RUN_DEPENDS=	zodb${PYTHON_PKGNAMESUFFIX}>=3.8.1:${PORTSDIR}/databases/zodb3 \
		${PYTHON_PKGNAMEPREFIX}zope.proxy>=3.4:${PORTSDIR}/net/py-zope.proxy \
		${PYTHON_PKGNAMEPREFIX}archetypes.schemaextender>=1.6:${PORTSDIR}/devel/py-archetypes.schemaextender \
		${PYTHON_PKGNAMEPREFIX}plone.app.imaging>1.0:${PORTSDIR}/www/py-plone.app.imaging \
		${PYTHON_PKGNAMEPREFIX}plone.scale>=0:${PORTSDIR}/www/py-plone.scale

USES=		zip
USE_PYTHON=		2
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

.include <bsd.port.mk>
