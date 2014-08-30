# Created by: Andrew Lewis <freeghb@gmail.com>
# $FreeBSD$

PORTNAME=	prosody
PORTVERSION=	0.9.4
PORTREVISION=	3
CATEGORIES=	net-im
MASTER_SITES=	http://prosody.im/downloads/source/ \
				http://redundancy.redundancy.org/mirror/

MAINTAINER=	lx@FreeBSD.org
COMMENT=	Simple extensible XMPP server written in Lua

LICENSE=	MIT

RUN_DEPENDS=	${LUA_MODLIBDIR}/socket/core.so:${PORTSDIR}/net/luasocket \
		${LUA_MODLIBDIR}/ssl.so:${PORTSDIR}/security/luasec \
		${LUA_MODLIBDIR}/lxp.so:${PORTSDIR}/textproc/luaexpat \
		${LUA_MODLIBDIR}/lfs.so:${PORTSDIR}/devel/luafilesystem-51

LIB_DEPENDS=	libidn.so:${PORTSDIR}/dns/libidn

USERS=		prosody
GROUPS=		${USERS}

USE_RC_SUBR=	prosody
MANCOMPRESSED=	no

OPTIONS_DEFINE= LUAJIT
LUAJIT_DESC=    Run prosody using luajit
LUAJIT_LIB_DEPENDS=     libluajit-5.1.so:${PORTSDIR}/lang/luajit

.include <bsd.port.options.mk>

USES=	gmake lua:51 shebangfix
SHEBANG_LANG=	lua
SHEBANG_FILES=	prosody prosodyctl
lua_OLD_CMD=	${SETENV} lua
lua_CMD=	${LOCALBASE}/bin/${LUA_CMD}
LUA_PREMK=	yes

.include <bsd.port.pre.mk>

HAS_CONFIGURE=	yes
.if ${PORT_OPTIONS:MLUAJIT}
CONFIGURE_ARGS+= --runwith=`which luajit`
.else
CONFIGURE_ARGS+= --runwith=`which ${LUA_CMD}`
.endif
CONFIGURE_ARGS+=	--ostype=freebsd --c-compiler="${CC}" --linker="${LD}" --with-lua-include="${LUA_INCDIR}"
CONFIGURE_ENV+=	LOCALBASE="${LOCALBASE}" PREFIX="${PREFIX}" LUA_SUFFIX="-${LUA_VER}" LUA_LIBDIR="${LUA_LIBDIR}" LUA_INCDIR="${LUA_INCDIR}"

SUB_FILES=	pkg-deinstall
SUB_LIST=	USERS=${USERS} GROUPS=${GROUPS}
PLIST_SUB=	PROSODY_USER=${USERS} PROSODY_GROUP=${GROUPS}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/prosody/util/*.so

.include <bsd.port.post.mk>
