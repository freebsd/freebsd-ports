# $FreeBSD$

PORTNAME=	bacula
PKGNAMESUFFIX=	-client

COMMENT=	Network backup solution (client)

WITH_CLIENT_ONLY=yes
USE_RC_SUBR=	bacula-fd

PLIST=		${PKGDIR}/pkg-plist.client
MASTERDIR=	${.CURDIR}/../../sysutils/bacula-server

OPTIONS_DEFINE=	NLS PYTHON ENABLE_IPV6
OPTIONS_DEFAULT=ENABLE_IPV6

ENABLE_IPV6_DESC=	Enable IPv6 support

.include "${MASTERDIR}/Makefile"
