# Created by: Edwin Groothuis <edwin@mavetju.org>
# $FreeBSD$

PORTNAME=	tolua
PORTVERSION=	5.1.3
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.tecgraf.puc-rio.br/pub/users/celes/tolua/ \
		http://www.tecgraf.puc-rio.br/~celes/tolua/

MAINTAINER=	edwin@mavetju.org
COMMENT=	toLua: accessing C/C++ code from Lua

USE_GMAKE=	yes
USE_LUA=	5.1
WRKSRC=		${WRKDIR}/${PORTNAME}-5.1.3

NO_STAGE=	yes
post-extract:
	${RM} ${WRKSRC}/src/bin/tolua_lua.o

post-patch:
	@${REINPLACE_CMD} -e 's|make|$${MAKE}|' ${WRKSRC}/${MAKEFILE}
	@${REINPLACE_CMD} -Ee \
		's|^(CC=).*|\1 ${CC}|; \
		 s|^(CCPP =).*|\1 ${CXX}|; \
		 s|^(LUA=).*|\1 ${LOCALBASE}|; \
		 s|^(LUA(INC\|LIB)=).*|\1 $${LUA_\2DIR}|; \
		 s|^(CPPFLAGS)(=.*)|\1+\2 -lstdc++|; \
		 s|^(CFLAGS)(=.*)|\1+\2|;' \
		${WRKSRC}/config

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/tolua ${LUA_BINDIR}
	${LN} -sf ${LUA_SUBDIR}/tolua ${PREFIX}/bin/tolua-${LUA_VER}
	${INSTALL_DATA} ${WRKSRC}/include/tolua.h ${LUA_INCDIR}
	${INSTALL_DATA} ${WRKSRC}/lib/libtolua.a ${LUA_LIBDIR}

.include <bsd.port.pre.mk>

.if ${ARCH} == "powerpc"
BROKEN=		Does not compile on powerpc
.endif
.if ${ARCH} == "sparc64" && ${OSVERSION} > 900000
BROKEN=		Does not install on sparc64-9
.endif

.include <bsd.port.post.mk>
