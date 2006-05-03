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

BUILD_DEPENDS=	${LOCALBASE}/include/lua.h:${PORTSDIR}/lang/lua50
RUN_DEPENDS=	${LOCALBASE}/include/lua.h:${PORTSDIR}/lang/lua50 \
		${LOCALBASE}/share/lua/5.0/compat-5.1.lua:${PORTSDIR}/devel/lua50-compat51

USE_GMAKE=	yes

post-extract:
	@ ${MV} ${WRKSRC}/makefile ${WRKSRC}/Makefile
	@ ${RM} ${WRKSRC}/src/compat-5.1r4/compat-5.1.o

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/luasocket
	@${INSTALL_DATA} ${WRKSRC}/doc/dns.html ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/doc/ftp.html ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/doc/home.html ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/doc/http.html ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/doc/installation.html ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/doc/introduction.html ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/doc/ltn12.html ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/doc/luasocket.png ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/doc/mime.html ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/doc/reference.css ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/doc/reference.html ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/doc/smtp.html ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/doc/socket.html ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/doc/tcp.html ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/doc/udp.html ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/doc/url.html ${DOCSDIR}
.endif

.include <bsd.port.mk>
