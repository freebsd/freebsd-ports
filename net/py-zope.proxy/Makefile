# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	zope.proxy
PORTVERSION=	4.1.3
PORTREVISION=	1
CATEGORIES=	net python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	zope

MAINTAINER=	zope@FreeBSD.org
COMMENT=	Generic Transparent Proxies

LICENSE=	ZPL21

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}zope.interface>=3.3.0:${PORTSDIR}/devel/py-zope.interface

USES=		zip
USE_PYTHON=		yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

.include <bsd.port.mk>
