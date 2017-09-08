# $FreeBSD$

PORTNAME=	bacula
PKGNAMESUFFIX=	5-client-static

COMMENT=	Network backup solution (static client)

DEPRECATED=	No upstream commits since 2013. Use sysutils/bacula-client-static
EXPIRATION_DATE=	2017-10-04

CONFLICTS=	bacula-client-static-*

PLIST=		${.CURDIR}/pkg-plist
MASTERDIR=	${.CURDIR}/../../sysutils/bacula5-server

PLIST_FILES=	sbin/bacula-fd-static \
		sbin/bconsole-static

OPTIONS_DEFINE=	NLS OPENSSL
OPTIONS_DEFAULT=OPENSSL

CONFIGURE_ARGS+=	--enable-client-only \
			--enable-static-fd \
			--enable-static-cons \
			--disable-libtool \
			--disable-build-dird \
			--disable-build-stored

BROKEN_aarch64=		Fails to link: missing sbrk

BROKEN_SSL=	libressl

.include "${MASTERDIR}/Makefile"
