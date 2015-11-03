# $FreeBSD$

PORTNAME=	bacula
PORTREVISION=	3
PKGNAMESUFFIX=	-client

COMMENT=	Network backup solution (client)

WITH_CLIENT_ONLY=yes
USE_RC_SUBR=	bacula-fd

PLIST=		${PKGDIR}/pkg-plist.client
MASTERDIR=	${.CURDIR}/../../sysutils/bacula-server

OPTIONS_DEFINE=	NLS PYTHON
OPTIONS_DEFAULT=#

.include "${MASTERDIR}/Makefile"
