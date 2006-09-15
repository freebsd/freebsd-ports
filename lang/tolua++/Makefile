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
DISTFILES=	tolua++-current${EXTRACT_SUFX}

MAINTAINER=	aaron@FreeBSD.org
COMMENT=	An extended version of tolua, a tool to integrate C/C++ code with Lua

BUILD_DEPENDS=	${LOCALBASE}/bin/scons:${PORTSDIR}/devel/scons

USE_BZIP2=	yes
USE_LDCONFIG=	yes
USE_LUA=	5.0
NO_BUILD=	yes

post-patch:
.for f in LOCALBASE LUA_VER LUA_INCDIR LUA_LIBDIR
	@${REINPLACE_CMD} -i "" -e 's|%%${f}%%|${${f}}|g' \
		${WRKSRC}/config_posix.py
.endfor

do-build:
	@cd ${WRKSRC} && scons

do-install:
	@cd ${WRKSRC} && scons prefix=${PREFIX} install

.include <bsd.port.mk>
