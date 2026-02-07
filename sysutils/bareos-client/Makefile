PORTNAME=	bareos

PKGNAMESUFFIX=	-client

COMMENT=	Backup archiving recovery open sourced (client)

CONFLICTS=	bareos22-client bareos23-client bareos24-client

USE_CXXSTD=	c++17

WITH_CLIENT_ONLY=yes
USE_RC_SUBR=	bareos-fd

PLIST=		${PKGDIR}/pkg-plist.client
MASTERDIR=	${.CURDIR}/../../sysutils/bareos-server

OPTIONS_DEFINE=	NLS PYTHON SCSICRYPTO

.include "${MASTERDIR}/Makefile"
