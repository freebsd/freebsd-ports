# New ports collection makefile for: 	luasocket
# Date created:				17 December 2002
# Whom:					Jan Hornyak <pav@oook.cz>
#
# $FreeBSD$
#

PORTNAME=	luasocket
PORTVERSION=	1.4
CATEGORIES=	net
MASTER_SITES=	http://www.cs.princeton.edu/~diego/professional/luasocket/old/luasocket-1.4/

MAINTAINER=	pav@FreeBSD.org
COMMENT=	IPv4 Sockets support for the Lua language

BUILD_DEPENDS=	${LOCALBASE}/include/lua.h:${PORTSDIR}/lang/lua4

post-extract:
	@ ${MV} ${WRKSRC}/makefile ${WRKSRC}/Makefile

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/luasocket ${PREFIX}/bin
	@ ${MKDIR} ${PREFIX}/lib/lua
	@ ${MKDIR} ${PREFIX}/lib/lua/luasocket
	@ ${INSTALL_DATA} ${WRKSRC}/lua/cl-compat.lua ${PREFIX}/lib/lua/luasocket
	@ ${INSTALL_DATA} ${WRKSRC}/lua/code.lua ${PREFIX}/lib/lua/luasocket
	@ ${INSTALL_DATA} ${WRKSRC}/lua/concat.lua ${PREFIX}/lib/lua/luasocket
	@ ${INSTALL_DATA} ${WRKSRC}/lua/ftp.lua ${PREFIX}/lib/lua/luasocket
	@ ${INSTALL_DATA} ${WRKSRC}/lua/http.lua ${PREFIX}/lib/lua/luasocket
	@ ${INSTALL_DATA} ${WRKSRC}/lua/README ${PREFIX}/lib/lua/luasocket
	@ ${INSTALL_DATA} ${WRKSRC}/lua/smtp.lua ${PREFIX}/lib/lua/luasocket
	@ ${INSTALL_DATA} ${WRKSRC}/lua/url.lua ${PREFIX}/lib/lua/luasocket

post-install:
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${PREFIX}/share/doc/luasocket
	@ ${INSTALL_DATA} ${WRKSRC}/html/anybrowser.png ${PREFIX}/share/doc/luasocket
	@ ${INSTALL_DATA} ${WRKSRC}/html/func.html ${PREFIX}/share/doc/luasocket
	@ ${INSTALL_DATA} ${WRKSRC}/html/home.html ${PREFIX}/share/doc/luasocket
	@ ${INSTALL_DATA} ${WRKSRC}/html/idx.html ${PREFIX}/share/doc/luasocket
	@ ${INSTALL_DATA} ${WRKSRC}/html/intro.html ${PREFIX}/share/doc/luasocket
	@ ${INSTALL_DATA} ${WRKSRC}/html/luasocket.png ${PREFIX}/share/doc/luasocket
	@ ${INSTALL_DATA} ${WRKSRC}/html/mod.html ${PREFIX}/share/doc/luasocket
	@ ${INSTALL_DATA} ${WRKSRC}/html/vim.png ${PREFIX}/share/doc/luasocket
.endif

.include <bsd.port.mk>
