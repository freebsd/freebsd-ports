# Created by: Andrew Lewis <freeghb@gmail.com>
# $FreeBSD$

PORTNAME=	prosody
PORTVERSION=	0.9.3
CATEGORIES=	net-im
MASTER_SITES=	http://prosody.im/downloads/source/ \
				http://redundancy.redundancy.org/mirror/

MAINTAINER=	lx@FreeBSD.org
COMMENT=	A simple extensible XMPP server written in Lua

LICENSE=	MIT

RUN_DEPENDS=	${LUA_MODLIBDIR}/socket/core.so:${PORTSDIR}/net/luasocket \
		${LUA_MODLIBDIR}/ssl.so:${PORTSDIR}/security/luasec \
		${LUA_MODLIBDIR}/lxp.so:${PORTSDIR}/textproc/luaexpat \
		${LUA_MODLIBDIR}/lfs.so:${PORTSDIR}/devel/luafilesystem \

LIB_DEPENDS=	libidn:${PORTSDIR}/dns/libidn

USERS=		prosody
GROUPS=		${USERS}

USE_RC_SUBR=	prosody
MANCOMPRESSED=	no

USES=	gmake shebangfix
USE_LUA=	5.1
WANT_LUA_VER=	5.1
SHEBANG_LANG=	lua
SHEBANG_FILES=	prosody prosodyctl
lua_OLD_CMD=	${SETENV} lua
lua_CMD=	${LUA_CMD}

HAS_CONFIGURE=	yes
CONFIGURE_ARGS+=	--ostype=freebsd --c-compiler="${CC}" --linker="${LD}"
CONFIGURE_ENV+=	LOCALBASE="${LOCALBASE}" PREFIX="${PREFIX}" LUA_SUFFIX="-${LUA_VER}" LUA_LIBDIR="${LUA_LIBDIR}" LUA_INCDIR="${LUA_INCDIR}"

SUB_FILES=	deinstall
SUB_LIST=	USERS=${USERS} GROUPS=${GROUPS}
PLIST_SUB=	PROSODY_USER=${USERS} PROSODY_GROUP=${GROUPS}

.include <bsd.port.mk>
