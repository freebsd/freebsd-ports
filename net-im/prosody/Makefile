# Created by: Andrew Lewis <freeghb@gmail.com>
# $FreeBSD$

PORTNAME=	prosody
PORTVERSION=	0.11.4
PORTREVISION=	1
CATEGORIES=	net-im
MASTER_SITES=	http://prosody.im/downloads/source/ \
		http://redundancy.redundancy.org/mirror/

MAINTAINER=	lx@FreeBSD.org
COMMENT=	Simple extensible XMPP server written in Lua

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${LUA_MODLIBDIR}/socket/core.so:net/luasocket \
		${LUA_MODLIBDIR}/ssl.so:security/luasec \
		${LUA_MODLIBDIR}/lxp.so:textproc/luaexpat \
		${LUA_MODLIBDIR}/lfs.so:devel/luafilesystem \
		${LUA_MODLIBDIR}/bit.so:devel/lua-bitop
LIB_DEPENDS=	libidn.so:dns/libidn

USES=		compiler:c11 cpe gmake lua:52 ssl
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
		--add-cflags="-fPIC -std=c99 -I${LOCALBASE}/include -I${OPENSSLINC}" \
		--linker="${CC}" \
		--ldflags="${LDFLAGS}" \
		--add-ldflags="-shared -L${LOCALBASE}/lib -L${OPENSSLLIB}" \
		--no-example-certs

MAKEFILE=	GNUmakefile
USERS=		prosody
GROUPS=		${USERS}

USE_RC_SUBR=	prosody
SUB_FILES=	pkg-deinstall
SUB_LIST=	USERS=${USERS} GROUPS=${GROUPS}
PLIST_SUB=	PROSODY_USER=${USERS} \
		PROSODY_USER_regex=\b${USERS}\b \
		PROSODY_GROUP=${GROUPS} \
		PROSODY_GROUP_regex=\b${GROUPS}\b

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/prosody/util/*.so
	@${MKDIR} ${STAGEDIR}/var/run/prosody
	@${RM} ${STAGEDIR}${ETCDIR}/certs/*

.include <bsd.port.mk>
