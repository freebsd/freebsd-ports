# Created by: Alonso Cardenas <acm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	bareos
PORTREVISION=	1
PKGNAMESUFFIX=	-client-static

COMMENT=	Backup archiving recovery open sourced (static client)

PLIST=		${.CURDIR}/pkg-plist
MASTERDIR=	${.CURDIR}/../../sysutils/bareos-server

PLIST_FILES=	sbin/bareos-fd-static \
		sbin/bconsole-static

OPTIONS_DEFINE=	NLS LMDB
OPTIONS_DEFAULT=#
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
