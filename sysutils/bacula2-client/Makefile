
# $FreeBSD$

PORTNAME=	bacula2
PKGNAMESUFFIX=  -client

MASTERDIR=	${.CURDIR}/../bacula2-server
COMMENT=	The network backup solution (client)
PLIST=		${PKGDIR}/pkg-plist.client

WITH_CLIENT_ONLY=	yes
USE_RC_SUBR=	bacula-fd

.include "${MASTERDIR}/Makefile"
