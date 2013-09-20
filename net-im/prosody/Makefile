# Created by: Andrew Lewis <freeghb@gmail.com>
# $FreeBSD$

PORTNAME=	prosody
PORTVERSION=	0.8.2
CATEGORIES=	net-im
MASTER_SITES=	http://prosody.im/downloads/source/ \
				http://redundancy.redundancy.org/mirror/

MAINTAINER=	lx@FreeBSD.org
COMMENT=	A simple extensible XMPP server written in Lua

RUN_DEPENDS=	${LUA_MODLIBDIR}/socket/core.so:${PORTSDIR}/net/luasocket \
		${LUA_MODLIBDIR}/ssl.so:${PORTSDIR}/security/luasec \
		${LUA_MODLIBDIR}/lxp.so:${PORTSDIR}/textproc/luaexpat \
		${LUA_MODLIBDIR}/lfs.so:${PORTSDIR}/devel/luafilesystem \

LIB_DEPENDS=	idn:${PORTSDIR}/dns/libidn

USE_RC_SUBR=	prosody
MAN1=	prosodyctl.1
MANCOMPRESSED=	no

USE_LUA=	5.1
WANT_LUA_VER=	5.1
USE_GMAKE=	yes

HAS_CONFIGURE=	yes
CONFIGURE_ARGS+="--ostype=freebsd"
CONFIGURE_ENV+=	LOCALBASE="${LOCALBASE}" PREFIX="${PREFIX}" LUA_SUFFIX="-${LUA_VER}" LUA_LIBDIR="${LUA_LIBDIR}" LUA_INCDIR="${LUA_INCDIR}"

SUB_FILES=	pkg-install pkg-deinstall

NO_STAGE=	yes
pre-install:
	${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL
	${REINPLACE_CMD} -e 's|/usr/bin/env lua|${LUA_CMD}|' ${WRKSRC}/prosody ${WRKSRC}/prosodyctl
	${RM} ${WRKSRC}/certs/localhost.*
	cd ${WRKSRC}/certs && ${GMAKE} localhost.cert

post-install:
	${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
