PORTNAME=	bareos

PORTREVISION=	0

PKGNAMESUFFIX=	24-client

COMMENT=	Backup archiving recovery open sourced (client)

CONFLICTS=	bareos22-client bareos23-client bareos-client

WITH_CLIENT_ONLY=yes
USE_RC_SUBR=	bareos-fd

PLIST=		${PKGDIR}/pkg-plist.client
MASTERDIR=	${.CURDIR}/../../sysutils/bareos24-server

OPTIONS_DEFINE=	NLS PYTHON SCSICRYPTO

.include "${MASTERDIR}/Makefile"
