PORTNAME=	bareos
PKGNAMESUFFIX=	22-client

COMMENT=	Backup archiving recovery open sourced (client)

CONFLICTS=	bareos-client bareos20-client bareos21-client

WITH_CLIENT_ONLY=yes
USE_RC_SUBR=	bareos-fd

PLIST=		${PKGDIR}/pkg-plist.client
MASTERDIR=	${.CURDIR}/../../sysutils/bareos22-server

OPTIONS_GROUP=	PLUGINS
OPTIONS_GROUP_PLUGINS=	GFAPI
OPTIONS_DEFINE=	NLS PYTHON SCSICRYPTO

GFAPI_DESC=	GFAPI fd plugin support

.include "${MASTERDIR}/Makefile"
