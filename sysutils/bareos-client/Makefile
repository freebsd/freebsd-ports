PORTNAME=	bareos
PKGNAMESUFFIX=	-client

COMMENT=	Backup archiving recovery open sourced (client)

CONFLICTS=	bareos20-client bareos19-client bareos18-client

WITH_CLIENT_ONLY=yes
USE_RC_SUBR=	bareos-fd

PLIST=		${PKGDIR}/pkg-plist.client
MASTERDIR=	${.CURDIR}/../../sysutils/bareos-server

OPTIONS_GROUP=	PLUGINS
OPTIONS_GROUP_PLUGINS=	GFAPI
OPTIONS_DEFINE=	NLS PYTHON SCSICRYPTO

GFAPI_DESC=	GFAPI fd plugin support

.include "${MASTERDIR}/Makefile"
