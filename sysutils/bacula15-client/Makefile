PORTNAME=	bacula
PKGNAMESUFFIX=	15-client

COMMENT=	Network backup solution (client)

WITH_CLIENT_ONLY=yes
USE_RC_SUBR=	bacula_fd

PLIST=		${PKGDIR}/pkg-plist.client
MASTERDIR=	${.CURDIR}/../../sysutils/bacula15-server

OPTIONS_DEFINE=	NLS PYTHON IPV6

.include "${MASTERDIR}/Makefile"
