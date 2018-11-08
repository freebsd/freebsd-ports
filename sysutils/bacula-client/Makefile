# $FreeBSD$

PORTNAME=	bacula
PKGNAMESUFFIX=	-client

COMMENT=	Network backup solution (client)

DEPRECATED=	Unsupported. Please migrate to bacula9-client
EXPIRATION_DATE=	2019-03-01

WITH_CLIENT_ONLY=yes
USE_RC_SUBR=	bacula-fd

PLIST=		${PKGDIR}/pkg-plist.client
MASTERDIR=	${.CURDIR}/../../sysutils/bacula-server

OPTIONS_DEFINE=	NLS PYTHON IPV6

BROKEN_aarch64=		Fails to link: missing sbrk

.include "${MASTERDIR}/Makefile"
