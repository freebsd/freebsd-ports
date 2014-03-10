# Created by: Jason Bacon <jwbacon@tds.net>
# $FreeBSD$

PORTNAME=	fiat
PORTVERSION=	${MMVERSION}.0
PORTREVISION=	2
CATEGORIES=	math python
MASTER_SITES=	https://launchpad.net/${PORTNAME}/${MMVERSION}.x/release-${MMVERSION}/+download/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}-${MMVERSION}

MAINTAINER=	jwbacon@tds.net
COMMENT=	FInite element Automatic Tabulator

LICENSE=	LGPL3

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}scientific>=0:${PORTSDIR}/math/py-scientific
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_PYTHON=	2
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	FIAT

MMVERSION=	1.1

NO_STAGE=	yes
.include <bsd.port.mk>
