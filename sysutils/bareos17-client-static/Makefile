# $FreeBSD$

PORTNAME=	bareos
PKGNAMESUFFIX=	17-client-static

COMMENT=	Backup archiving recovery open sourced (static client)

CONFLICTS=	bareos16-client-static-*

PLIST=		${.CURDIR}/pkg-plist
MASTERDIR=	${.CURDIR}/../../sysutils/bareos17-server

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

BROKEN_aarch64=	Fails to link: missing sbrk

.include "${MASTERDIR}/Makefile"
