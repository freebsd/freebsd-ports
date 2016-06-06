# Created by: fluffy
# $FreeBSD$

PKGNAMESUFFIX=		-filter-lua
PORTREVISION=		0

COMMENT=		LUA-script filter support for OpenSMTPD
MAINTAINER=		fluffy@FreeBSD.org

PLIST_FILES=		libexec/opensmtpd/filter-lua

CONFIGURE_ARGS+=	--with-filter-lua --with-lua-type=lua-${LUA_VER}

USES=			lua pkgconfig

MASTERDIR=		${.CURDIR}/../opensmtpd-extras
SLAVE_PORT=		yes

.include "${MASTERDIR}/Makefile"
