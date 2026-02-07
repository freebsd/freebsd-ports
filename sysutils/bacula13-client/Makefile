PORTNAME=	bacula
PKGNAMESUFFIX=	13-client

COMMENT=	Network backup solution (client)

WITH_CLIENT_ONLY=yes
USE_RC_SUBR=	bacula_fd

PLIST=		${PKGDIR}/pkg-plist.client
MASTERDIR=	${.CURDIR}/../../sysutils/bacula13-server

OPTIONS_DEFINE=	NLS PYTHON IPV6

.include "${MASTERDIR}/Makefile"
