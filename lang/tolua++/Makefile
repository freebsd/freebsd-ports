# New ports collection makefile for:    tolua++
# Date created:         18 Jan 2006
# Whom:                 aaron@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	tolua++
PORTVERSION=	1.0.4
CATEGORIES=	lang devel
MASTER_SITES=	http://www.codenix.com/~tolua/
DISTNAME=	tolua++-current

MAINTAINER=	aaron@FreeBSD.org
COMMENT=	An extended version of tolua, a tool to integrate C/C++ code with Lua

BUILD_DEPENDS=	${LOCALBASE}/bin/scons:${PORTSDIR}/devel/scons
LIB_DEPENDS=	lua:${PORTSDIR}/lang/lua50

WRKSRC=		${WRKDIR}/tolua++-${PORTVERSION}
USE_BZIP2=	yes
INSTALLS_SHLIB=	yes
NO_BUILD=	yes

do-build:
	@cd ${WRKSRC} && scons

do-install:
	@cd ${WRKSRC} && scons prefix=${PREFIX} install

.include <bsd.port.mk>
