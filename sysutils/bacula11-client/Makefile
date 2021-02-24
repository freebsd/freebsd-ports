# $FreeBSD$

PORTNAME=	bacula
PKGNAMESUFFIX=	11-client

COMMENT=	Network backup solution (client)

BROKEN_aarch64=		Fails to link: missing sbrk
BROKEN_riscv64=		Fails to link: missing sbrk

WITH_CLIENT_ONLY=yes
USE_RC_SUBR=	bacula-fd

PLIST=		${PKGDIR}/pkg-plist.client
MASTERDIR=	${.CURDIR}/../../sysutils/bacula11-server

OPTIONS_DEFINE=	NLS PYTHON IPV6

.include "${MASTERDIR}/Makefile"
