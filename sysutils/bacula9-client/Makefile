# $FreeBSD$

PORTNAME=	bacula
PKGNAMESUFFIX=	9-client

COMMENT=	Network backup solution (client)

WITH_CLIENT_ONLY=yes
USE_RC_SUBR=	bacula-fd

PLIST=		${PKGDIR}/pkg-plist.client
MASTERDIR=	${.CURDIR}/../../sysutils/bacula9-server

OPTIONS_DEFINE=	NLS PYTHON IPV6

BROKEN_aarch64=		Fails to link: missing sbrk

.include "${MASTERDIR}/Makefile"
