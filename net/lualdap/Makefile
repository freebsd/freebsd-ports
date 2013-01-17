# Created by: Piotr Florczyk <pf@itwf.pl>
# $FreeBSD$

PORTNAME=	lualdap
PORTVERSION=	1.1.0
CATEGORIES=	net
MASTER_SITES=	http://files.luaforge.net/releases/${PORTNAME}/${PORTNAME}/LuaLDAP${PORTVERSION}/
PKGNAMEPREFIX=	${LUA_PKGNAMEPREFIX}

MAINTAINER=	pf@itwf.pl
COMMENT=	LDAP support for the Lua language

USE_GMAKE=	yes
USE_LUA=	5.1+
USE_OPENLDAP=	yes

# the CPPFLAGS fixes builds where PREFIX != LOCALBASE
CPPFLAGS+=	-I${LOCALBASE}/include/${LUA_SUBDIR}
MAKE_ARGS+=	LUA_LIBDIR="${LUA_LIBDIR}" \
		LUA_INC="${LUA_INCDIR}" \
		OPENLDAP_LIB="-L${LOCALBASE}/lib -lldap" \
		LUA_VERSION_NUM="${LUA_VER_STR}0"

ALL_TARGET=

.include <bsd.port.pre.mk>

do-install:
	${MKDIR} ${LUA_MODLIBDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/src/lualdap.so.${PORTVERSION} ${LUA_MODLIBDIR}/${PORTNAME}.so
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/doc/us/* ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
