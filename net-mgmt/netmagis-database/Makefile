# Created by: Pierre David <pdagog@gmail.com>, Jean Benoit <jean@unistra.fr>
# $FreeBSD$

PORTNAME=	netmagis
PKGNAMESUFFIX=	-database

COMMENT=	Utilities for the netmagis database server

RUN_DEPENDS=	netmagis-config:${PORTSDIR}/net-mgmt/netmagis-common \
		pwgen:${PORTSDIR}/sysutils/pwgen \
		tcltls>=1.4.1:${PORTSDIR}/devel/tcltls \
		${LOCALBASE}/share/certs/ca-root-nss.crt:${PORTSDIR}/security/ca_root_nss

WANT_PGSQL+=	server pltcl

MASTERDIR=	${.CURDIR}/../netmagis-common

NO_ARCH=	yes

PKGMESSAGE=	${.CURDIR}/pkg-message
PLIST=		${.CURDIR}/pkg-plist

.include "${MASTERDIR}/Makefile"
