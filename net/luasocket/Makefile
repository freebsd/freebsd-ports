# New ports collection makefile for: 	luasocket
# Date created:				17 December 2002
# Whom:					Jan Hornyak <pav@oook.cz>
#
# $FreeBSD$
#

PORTNAME=	luasocket
PORTVERSION=	2.0
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://luaforge.net/frs/download.php/1097/

MAINTAINER=	andrew+ports@fubar.geek.nz
COMMENT=	IPv4 Sockets support for the Lua language

BUILD_DEPENDS=	${NONEXISTENT}:${PORTSDIR}/devel/lua50-compat51:extract

USE_GMAKE=	yes
USE_LUA=	5.0
LUA_COMPS=	lua compat51

COMPAT_SRC=	`(cd ${PORTSDIR}/devel/lua50-compat51 && ${MAKE} -V WRKSRC)`
MAKE_ENV=	COMPATDIR="${COMPAT_SRC}"

post-extract:
	@${MV} ${WRKSRC}/makefile ${WRKSRC}/Makefile

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/doc/* ${DOCSDIR}
.endif

.include <bsd.port.mk>
