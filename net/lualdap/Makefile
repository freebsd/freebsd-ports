# Created by: Piotr Florczyk <pf@itwf.pl>
# $FreeBSD$

PORTNAME=	lualdap
PORTVERSION=	1.1.0
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://files.luaforge.net/releases/${PORTNAME}/${PORTNAME}/LuaLDAP${PORTVERSION}/
PKGNAMEPREFIX=	${LUA_PKGNAMEPREFIX}

MAINTAINER=	pf@itwf.pl
COMMENT=	LDAP support for the Lua language

USES=		gmake lua
USE_OPENLDAP=	yes

# the CPPFLAGS fixes builds where PREFIX != LOCALBASE
CPPFLAGS+=	-I${LOCALBASE}/include/${LUA_SUBDIR}
MAKE_ARGS+=	LUA_LIBDIR="${LUA_LIBDIR}" \
		LUA_INC="${LUA_INCDIR}" \
		OPENLDAP_LIB="-L${LOCALBASE}/lib -lldap" \
		LUA_VERSION_NUM="${LUA_VER_STR}0" \
		CC="${CC}"

ALL_TARGET=

do-install:
	@${MKDIR} ${STAGEDIR}${LUA_MODLIBDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/src/lualdap.so.${PORTVERSION} ${STAGEDIR}${LUA_MODLIBDIR}/${PORTNAME}.so
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/us/* ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
