PORTNAME=	prosody
DISTVERSION=	0.12.1
CATEGORIES=	net-im
MASTER_SITES=	https://prosody.im/downloads/source/

MAINTAINER=	thomas@beingboiled.info
COMMENT=	Simple extensible XMPP server written in Lua

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libicudata.so:devel/icu \
		libicui18n.so:devel/icu \
		libicuuc.so:devel/icu
RUN_DEPENDS=	${LUA_REFMODLIBDIR}/bit.so:devel/lua-bitop@${LUA_FLAVOR} \
		${LUA_REFMODLIBDIR}/lfs.so:devel/luafilesystem@${LUA_FLAVOR} \
		${LUA_REFMODLIBDIR}/luaevent/core.so:devel/lua-libevent@${LUA_FLAVOR} \
		${LUA_REFMODLIBDIR}/lunbound.so:dns/luaunbound@${LUA_FLAVOR} \
		${LUA_REFMODLIBDIR}/lxp.so:textproc/luaexpat@${LUA_FLAVOR} \
		${LUA_REFMODLIBDIR}/socket/core.so:net/luasocket@${LUA_FLAVOR} \
		${LUA_REFMODLIBDIR}/ssl.so:security/luasec@${LUA_FLAVOR}

USES=		cpe gmake lua:54 shebangfix ssl
SHEBANG_FILES=	prosody prosodyctl tools/migration/prosody-migrator.lua
LUA_PREMK=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix="${PREFIX}" \
		--datadir="/var/db/prosody" \
		--lua-version="${LUA_VER}" \
		--lua-suffix="${LUA_VER_STR}" \
		--with-lua-include="${LUA_INCDIR}" \
		--with-lua-lib="${LUA_LIBDIR}" \
		--with-random=arc4random \
		--c-compiler="${CC}" \
		--cflags="${CFLAGS}" \
		--add-cflags="-fPIC -I${LOCALBASE}/include -I${OPENSSLINC}" \
		--linker="${CC}" \
		--ldflags="${LDFLAGS}" \
		--add-ldflags="-shared -L${LOCALBASE}/lib -L${OPENSSLLIB}" \
		--no-example-certs

MAKEFILE=	GNUmakefile
USERS=		prosody
GROUPS=		${USERS}

USE_RC_SUBR=	prosody
SUB_FILES=	pkg-deinstall
SUB_LIST=	USERS=${USERS} GROUPS=${GROUPS} LUA_PREFIX=${LUA_PREFIX} LUA_CMD=${LUA_CMD}
PLIST_SUB=	PROSODY_USER=${USERS} PROSODY_GROUP=${GROUPS}

post-install:
	@${REINPLACE_CMD} -e "s|\"luarocks |\"luarocks${LUA_VER_STR} |" ${STAGEDIR}${PREFIX}/lib/prosody/util/prosodyctl.lua
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/prosody/util/*.so
	@${MKDIR} ${STAGEDIR}/var/run/prosody
	@${RM} ${STAGEDIR}${ETCDIR}/certs/*

.include <bsd.port.mk>
