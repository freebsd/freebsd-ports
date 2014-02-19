# Created by: Jan Hornyak <pav@oook.cz>
# $FreeBSD$

PORTNAME=	luasocket
PORTVERSION=	3.0r1
CATEGORIES=	net
PKGNAMEPREFIX=	${LUA_PKGNAMEPREFIX}

MAINTAINER=	lx@FreeBSD.org
COMMENT=	IPv4 and IPv6 socket support for the Lua language

LICENSE=	MIT

USE_GITHUB=	yes
GH_ACCOUNT=	diegonehab
GH_PROJECT=	${PORTNAME}
GH_TAGNAME=	v3.0-rc1
GH_COMMIT=	22cd583

USE_GMAKE=	yes
USE_LUA?=	5.1
LUA_COMPS=	lua

CFLAGS+=    `pkgconf --cflags lua-${LUA_VER}` -I${LUA_INCDIR}
LDFLAGS+=   -shared -L${LOCALBASE}/lib -L${LUA_LIBDIR}

post-extract:
	@${MV} ${WRKSRC}/makefile ${WRKSRC}/Makefile
	@${MV} ${WRKSRC}/src/makefile ${WRKSRC}/src/Makefile
	@${REINPLACE_CMD} -e 's/gcc/${CC}/g' ${WRKSRC}/src/Makefile
	@${REINPLACE_CMD} -e 's/CFLAGS=/CFLAGS\+=/g' ${WRKSRC}/src/Makefile
	@${REINPLACE_CMD} -e 's/LDFLAGS=/LDFLAGS\+=/g' ${WRKSRC}/src/Makefile
	@${REINPLACE_CMD} -e 's/prefix/PREFIX/g' ${WRKSRC}/src/Makefile

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${STAGEDIR}/${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/doc/* ${STAGEDIR}/${DOCSDIR}
.endif

.include <bsd.port.mk>
