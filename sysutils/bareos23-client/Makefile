PORTNAME=	bareos
PKGNAMESUFFIX=	23-client

COMMENT=	Backup archiving recovery open sourced (client)

CONFLICTS=	bareos24-client bareos22-client bareos-client

WITH_CLIENT_ONLY=yes
USE_RC_SUBR=	bareos-fd

PLIST=		${PKGDIR}/pkg-plist.client
MASTERDIR=	${.CURDIR}/../../sysutils/bareos23-server

OPTIONS_DEFINE=	NLS PYTHON SCSICRYPTO

.include "${MASTERDIR}/Makefile"
