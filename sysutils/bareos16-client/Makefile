# $FreeBSD$

PORTNAME=	bareos
PKGNAMESUFFIX=	16-client

COMMENT=	Backup archiving recovery open sourced (client)

BROKEN_aarch64=	Fails to link: missing sbrk
BROKEN_FreeBSD_13_powerpc64=	fails to compile: bsnprintf.c:621:16: static declaration of 'round' follows non-static declaration

CONFLICTS=	bareos-client-*

WITH_CLIENT_ONLY=yes
USE_RC_SUBR=	bareos-fd

PLIST=		${PKGDIR}/pkg-plist.client
MASTERDIR=	${.CURDIR}/../../sysutils/bareos16-server

OPTIONS_DEFINE=	NLS PYTHON LMDB SCSICRYPTO
LMDB_DESC=	Enable build of LMDB support

.include "${MASTERDIR}/Makefile"
