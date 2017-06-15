# Created by: fluffy
# $FreeBSD$

PKGNAMESUFFIX=		-filter-lua
PORTREVISION=		2

COMMENT=		LUA-script filter support for OpenSMTPD

PLIST_FILES=		libexec/opensmtpd/filter-lua

CONFIGURE_ARGS+=	--with-experimental-filter-lua --with-lua-type=lua-${LUA_VER}

USES=			lua pkgconfig

MASTERDIR=		${.CURDIR}/../opensmtpd-extras
SLAVE_PORT=		yes

.include "${MASTERDIR}/Makefile"
