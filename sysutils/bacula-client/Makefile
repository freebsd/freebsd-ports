
# $FreeBSD$

PORTNAME=	bacula
PKGNAMESUFFIX=  -client

MASTERDIR=	${.CURDIR}/../bacula-server
COMMENT=	The network backup solution (client)
PLIST=		${PKGDIR}/pkg-plist.client

WITH_CLIENT_ONLY=	yes
USE_RC_SUBR=	z-bacula-fd.sh

.include "${MASTERDIR}/Makefile"
