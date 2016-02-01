# Created by: Alonso Cardenas <acm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	bareos
PORTREVISION=	2
PKGNAMESUFFIX=	-client

COMMENT=	Backup archiving recovery open sourced (client)

WITH_CLIENT_ONLY=yes
USE_RC_SUBR=	bareos-fd

PLIST=		${PKGDIR}/pkg-plist.client
MASTERDIR=	${.CURDIR}/../../sysutils/bareos-server

OPTIONS_DEFINE=	NLS PYTHON LMDB
OPTIONS_DEFAULT=#
LMDB_DESC=	Enable build of LMDB support

.include "${MASTERDIR}/Makefile"
