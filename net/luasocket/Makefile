# New ports collection makefile for: 	luasocket
# Date created:				17 December 2002
# Whom:					Jan Hornyak <pav@oook.cz>
#
# $FreeBSD$
#

PORTNAME=	luasocket
PORTVERSION=	2.0.2
CATEGORIES=	net
MASTER_SITES=	http://luaforge.net/frs/download.php/2664/
PKGNAMEPREFIX=	${LUA_PKGNAMEPREFIX}

MAINTAINER=	apache@FreeBSD.org
COMMENT=	IPv4 Sockets support for the Lua language

USE_GMAKE=	yes
USE_LUA?=	5.1
LUA_COMPS=	lua

.if ${USE_LUA} == 5.0
LUA_COMPS+=	compat51

BUILD_DEPENDS+=	${NONEXISTENT}:${PORTSDIR}/devel/lua50-compat51:build
COMPAT_SRC=	`(cd ${PORTSDIR}/devel/lua50-compat51 && ${MAKE} -V WRKSRC)`
MAKE_ENV=	COMPATDIR="${COMPAT_SRC}" \
		COMPAT_OBJ="${COMPAT_SRC}/compat-5.1.o"
.endif

post-extract:
	@${MV} ${WRKSRC}/makefile ${WRKSRC}/Makefile

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/doc/* ${DOCSDIR}
.endif

.include <bsd.port.mk>
