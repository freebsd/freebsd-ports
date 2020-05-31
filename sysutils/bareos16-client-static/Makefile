# $FreeBSD$

PORTNAME=	bareos
PKGNAMESUFFIX=	16-client-static

COMMENT=	Backup archiving recovery open sourced (static client)

BROKEN_aarch64=	Fails to link: missing sbrk
BROKEN_FreeBSD_13_powerpc64=	fails to compile: bsnprintf.c:621:16: static declaration of 'round' follows non-static declaration
 
CONFLICTS=	bareos-client-static-*

PLIST=		${.CURDIR}/pkg-plist
MASTERDIR=	${.CURDIR}/../../sysutils/bareos16-server

PLIST_FILES=	sbin/bareos-fd-static \
		sbin/bconsole-static

OPTIONS_DEFINE=	NLS LMDB
LMDB_DESC=	Enable build of LMDB support

CONFIGURE_ARGS+=	--enable-client-only \
			--enable-static-fd \
			--enable-static-cons \
			--disable-libtool \
			--disable-build-dird \
			--disable-build-stored \
			--with-jansson=${LOCALBASE}

.include "${MASTERDIR}/Makefile"
