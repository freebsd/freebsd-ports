PORTNAME=	bareos
PORTREVISION=	1
PKGNAMESUFFIX=	23-client

COMMENT=	Backup archiving recovery open sourced (client)

CONFLICTS=	bareos22-client bareos21-client bareos20-client bareos-client

WITH_CLIENT_ONLY=yes
USE_RC_SUBR=	bareos-fd

PLIST=		${PKGDIR}/pkg-plist.client
MASTERDIR=	${.CURDIR}/../../sysutils/bareos23-server

OPTIONS_GROUP=	PLUGINS
OPTIONS_GROUP_PLUGINS=	GFAPI
OPTIONS_DEFINE=	NLS PYTHON SCSICRYPTO

GFAPI_DESC=	GFAPI fd plugin support

.include "${MASTERDIR}/Makefile"
