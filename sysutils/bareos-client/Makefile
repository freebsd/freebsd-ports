# $FreeBSD$

PORTNAME=	bareos
PKGNAMESUFFIX=	-client

COMMENT=	Backup archiving recovery open sourced (client)

CONFLICTS=	bareos19-client-* bareos18-client-* bareos17-client-*

WITH_CLIENT_ONLY=yes
USE_RC_SUBR=	bareos-fd

PLIST=		${PKGDIR}/pkg-plist.client
MASTERDIR=	${.CURDIR}/../../sysutils/bareos-server

OPTIONS_GROUP=	PLUGINS
OPTIONS_GROUP_PLUGINS= CEPHFS GFAPI RADOS
OPTIONS_DEFINE=	NLS PYTHON SCSICRYPTO

CEPHFS_DESC=	CEPHFS fd plugin support
GFAPI_DESC=	GFAPI fd plugin support
RADOS_DESC=	RADOS fd plugin support

.include "${MASTERDIR}/Makefile"
