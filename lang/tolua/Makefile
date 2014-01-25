# Created by: Edwin Groothuis <edwin@mavetju.org>
# $FreeBSD$

PORTNAME=	tolua
PORTVERSION=	5.2.0
CATEGORIES=	lang
MASTER_SITES=	http://www.tecgraf.puc-rio.br/~celes/tolua/ \
		ftp://ftp.tecgraf.puc-rio.br/pub/users/celes/tolua/

MAINTAINER=	lua@FreeBSD.org
COMMENT=	toLua: accessing C/C++ code from Lua

USES=		gmake lua

MAKE_ARGS=	CC="${CC}" CCPP="${CXX}" \
		LUAINC="${LUA_INCDIR}" \
		LUALIB="${LUA_LIBDIR}" \
		WARN="${CFLAGS}"

post-patch:
	@${REINPLACE_CMD} -e 's|make|$${MAKE}|' ${WRKSRC}/${MAKEFILE}
	@${REINPLACE_CMD} -e 's|llua|llua-${LUA_VER}|' \
		${WRKSRC}/src/bin/${MAKEFILE} \
		${WRKSRC}/src/tests/${MAKEFILE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/tolua ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/include/tolua.h ${STAGEDIR}${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/lib/libtolua.a ${STAGEDIR}${PREFIX}/lib

.include <bsd.port.mk>
