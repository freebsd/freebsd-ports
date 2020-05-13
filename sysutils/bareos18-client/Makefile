# $FreeBSD$

PORTNAME=	bareos
PKGNAMESUFFIX=	18-client

COMMENT=	Backup archiving recovery open sourced (client)

BROKEN_aarch64=	Fails to link: missing sbrk

CONFLICTS=	bareos17-client-* bareos16-client-* bareos-client-*

WITH_CLIENT_ONLY=yes
USE_RC_SUBR=	bareos-fd

PLIST=		${PKGDIR}/pkg-plist.client
MASTERDIR=	${.CURDIR}/../../sysutils/bareos18-server

OPTIONS_DEFINE=	NLS PYTHON LMDB SCSICRYPTO
LMDB_DESC=	Enable build of LMDB support

.include "${MASTERDIR}/Makefile"
