# Created by: Andrew Lewis <freeghb@gmail.com>
# $FreeBSD$

PORTNAME=	prosody
PORTVERSION=	0.10.2
CATEGORIES=	net-im
MASTER_SITES=	http://prosody.im/downloads/source/ \
		http://redundancy.redundancy.org/mirror/

MAINTAINER=	lx@FreeBSD.org
COMMENT=	Simple extensible XMPP server written in Lua

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${LUA_MODLIBDIR}/socket/core.so:net/luasocket-51 \
		${LUA_MODLIBDIR}/ssl.so:security/luasec-51 \
		${LUA_MODLIBDIR}/lxp.so:textproc/luaexpat-51 \
		${LUA_MODLIBDIR}/lfs.so:devel/luafilesystem-51 \
		${LUA_MODLIBDIR}/bit.so:devel/lua51-bitop
LIB_DEPENDS=	libidn.so:dns/libidn

USES=		compiler:c11 cpe gmake lua:51 shebangfix ssl
SHEBANG_FILES=	prosody prosodyctl
LUA_PREMK=	yes
HAS_CONFIGURE=	yes
CFLAGS+=	-I${OPENSSLINC}
LDFLAGS+=	-L${OPENSSLLIB}
CONFIGURE_ARGS=	--ostype=freebsd \
		--c-compiler="${CC}" \
		--linker="${CC}" \
		--with-lua-include="${LUA_INCDIR}"
CONFIGURE_ENV=	LOCALBASE="${LOCALBASE}" \
		PREFIX="${PREFIX}" \
		LUA_SUFFIX="-${LUA_VER}" \
		LUA_LIBDIR="${LUA_LIBDIR}" \
		LUA_INCDIR="${LUA_INCDIR}"

USERS=		prosody
GROUPS=		${USERS}

USE_RC_SUBR=	prosody
SUB_FILES=	pkg-deinstall
SUB_LIST=	USERS=${USERS} GROUPS=${GROUPS}
PLIST_SUB=	PROSODY_USER=${USERS} PROSODY_GROUP=${GROUPS}

OPTIONS_DEFINE=	LUAJIT
LUAJIT_DESC=		Run prosody using luajit
LUAJIT_LIB_DEPENDS=	libluajit-5.1.so:lang/luajit

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MLUAJIT}
lua_CMD=	${LOCALBASE}/bin/luajit
.else
lua_CMD=	${LOCALBASE}/bin/${LUA_CMD}
.endif

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/prosody/util/*.so

.include <bsd.port.mk>
