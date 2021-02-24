# $FreeBSD$

PORTNAME=	bacula
PKGNAMESUFFIX=	11-client-static

COMMENT=	Network backup solution (static client)

BROKEN_aarch64=		Fails to link: missing sbrk
BROKEN_riscv64=		Fails to link: missing sbrk
BROKEN_SSL=	libressl

WITH_CLIENT_ONLY=yes
PLIST=		${.CURDIR}/pkg-plist
MASTERDIR=	${.CURDIR}/../../sysutils/bacula11-server

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

.include "${MASTERDIR}/Makefile"
