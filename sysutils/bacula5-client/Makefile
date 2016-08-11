# $FreeBSD$

PORTNAME=	bacula
PKGNAMESUFFIX=	5-client

COMMENT=	Network backup solution (client)

CONFLICTS=	bacula-client-*

WITH_CLIENT_ONLY=yes
USE_RC_SUBR=	bacula-fd

PLIST=		${PKGDIR}/pkg-plist.client
MASTERDIR=	${.CURDIR}/../../sysutils/bacula5-server

OPTIONS_DEFINE=	NLS OPENSSL PYTHON
OPTIONS_DEFAULT=OPENSSL

.include "${MASTERDIR}/Makefile"
