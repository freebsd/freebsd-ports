# Created by: aaron@FreeBSD.org
# $FreeBSD$

PORTNAME=	tolua++
PORTVERSION=	1.0.92
PORTREVISION=	2
PKGNAMESUFFIX=	50
CATEGORIES=	lang devel
MASTER_SITES=	http://www.codenix.com/~tolua/ \
		http://mirror.amdmi3.ru/distfiles/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	An extended version of tolua, a tool to integrate C/C++ code with Lua

USE_BZIP2=	yes
USE_LUA=	5.0
USE_SCONS=	yes
SCONS_ARGS=	prefix=${PREFIX} SONAME="libtolua++-${LUA_VER}.so"

CFLAGS+=	-I${LUA_INCDIR}
LDFLAGS+=	-L${LUA_LIBDIR}

TGT_BINDIR=	${LUA_BINDIR:C/^${LOCALBASE}/${PREFIX}/}
TGT_INCDIR=	${LUA_INCDIR:C/^${LOCALBASE}/${PREFIX}/}
TGT_LIBDIR=	${LUA_LIBDIR:C/^${LOCALBASE}/${PREFIX}/}

PORTSCOUT=	limit:1\.0\.92

do-install:
	${MKDIR} ${STAGEDIR}${TGT_BINDIR} ${STAGEDIR}${TGT_INCDIR} ${STAGEDIR}${TGT_LIBDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/bin/tolua++ ${STAGEDIR}${TGT_BINDIR}
	${LN} -sf ${LUA_SUBDIR}/tolua++ ${STAGEDIR}${PREFIX}/bin/tolua++-${LUA_VER}
	${INSTALL_DATA} ${WRKSRC}/include/tolua++.h ${STAGEDIR}${TGT_INCDIR}
	${INSTALL_DATA} ${WRKSRC}/lib/libtolua++.a ${STAGEDIR}${TGT_LIBDIR}
	${INSTALL_DATA} ${WRKSRC}/lib/libtolua++.so ${STAGEDIR}${TGT_LIBDIR}
	${INSTALL_DATA} ${WRKSRC}/lib/libtolua++.so ${STAGEDIR}${PREFIX}/lib/libtolua++-${LUA_VER}.so

.include <bsd.port.mk>
