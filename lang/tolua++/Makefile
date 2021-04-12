# Created by: aaron@FreeBSD.org

PORTNAME=	tolua++
PORTVERSION=	1.0.93
PORTREVISION=	3
CATEGORIES=	lang devel
MASTER_SITES=	http://www.codenix.com/~tolua/ \
		http://mirror.amdmi3.ru/distfiles/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Extended version of tolua, a tool to integrate C/C++ code with Lua

USES=		scons lua:51 tar:bzip2
MAKE_ARGS=	prefix=${PREFIX} SONAME="libtolua++-${LUA_VER}.so"

CCFLAGS+=	-I${LUA_INCDIR}
LDFLAGS+=	-L${LUA_LIBDIR}

TGT_BINDIR=	${PREFIX}/bin
TGT_INCDIR=	${LUA_INCDIR:C/^${LOCALBASE}/${PREFIX}/}
TGT_LIBDIR=	${LUA_LIBDIR:C/^${LOCALBASE}/${PREFIX}/}

post-patch:
	@${REINPLACE_CMD} -e "s|'lualib',||; s|lua|lua-${LUA_VER}|g" ${WRKSRC}/config_posix.py

do-install:
	${MKDIR} ${STAGEDIR}${TGT_BINDIR} ${STAGEDIR}${TGT_INCDIR} ${STAGEDIR}${TGT_LIBDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/bin/tolua++ ${STAGEDIR}${TGT_BINDIR}
	${LN} -sf tolua++ ${STAGEDIR}${PREFIX}/bin/tolua++-${LUA_VER}
	${INSTALL_DATA} ${WRKSRC}/include/tolua++.h ${STAGEDIR}${TGT_INCDIR}
	${INSTALL_DATA} ${WRKSRC}/lib/libtolua++.a ${STAGEDIR}${TGT_LIBDIR}
	${INSTALL_LIB} ${WRKSRC}/lib/libtolua++.so ${STAGEDIR}${TGT_LIBDIR}
	${INSTALL_LIB} ${WRKSRC}/lib/libtolua++.so ${STAGEDIR}${PREFIX}/lib/libtolua++-${LUA_VER}.so

.include <bsd.port.mk>
