# $FreeBSD$

PORTNAME=	bacula
PORTREVISION=	1
PKGNAMESUFFIX=	-client-static

COMMENT=	Network backup solution (static client)

PLIST=		${.CURDIR}/pkg-plist
MASTERDIR=	${.CURDIR}/../../sysutils/bacula-server

PLIST_FILES=	sbin/bacula-fd-static \
		sbin/bconsole-static

OPTIONS_DEFINE=	NLS OPENSSL
OPTIONS_DEFAULT=NLS OPENSSL

CONFIGURE_ARGS+=	--enable-client-only \
			--enable-static-fd \
			--enable-static-cons \
			--disable-libtool \
			--disable-build-dird \
			--disable-build-stored

.include "${MASTERDIR}/Makefile"
