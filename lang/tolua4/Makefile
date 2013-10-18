# Created by: Edwin Groothuis <edwin@mavetju.org>
# $FreeBSD$

PORTNAME=	tolua
PORTVERSION=	4.0a
PORTREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.tecgraf.puc-rio.br/pub/users/celes/tolua/ \
		http://www.tecgraf.puc-rio.br/~celes/tolua/
PKGNAMESUFFIX=	${LUA_VER_STR}

MAINTAINER=	edwin@mavetju.org
COMMENT=	Tool for easy access of C/C++ code from Lua

USES=		gmake
USE_LUA=	4.0
WRKSRC=		${WRKDIR}/${PORTNAME}

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -Ee \
		's|^(CC=).*|\1 ${CC}|; \
		 s|^(LUA=).*|\1 ${LOCALBASE}|; \
		 s|^(LUA(INC\|LIB)=.*)|\1/lua${LUA_VER_STR}|; \
		 s|^(CFLAGS)(=.*)|\1+\2|;' \
		${WRKSRC}/config
	@${REINPLACE_CMD} -E 's|cd (.+); make|$$(MAKE) -C \1|' \
		${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/tolua ${LUA_BINDIR}
	${LN} -sf ${LUA_SUBDIR}/tolua ${PREFIX}/bin/tolua-${LUA_VER}
	${INSTALL_DATA} ${WRKSRC}/include/tolua.h ${LUA_INCDIR}
	${INSTALL_DATA} ${WRKSRC}/lib/libtolua.a ${LUA_LIBDIR}

.include <bsd.port.mk>
