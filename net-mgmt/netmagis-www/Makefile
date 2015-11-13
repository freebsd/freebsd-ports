# Created by: Pierre David <pdagog@gmail.com>, Jean Benoit <jean@unistra.fr>
# $FreeBSD$

PORTNAME=	netmagis
PKGNAMESUFFIX=	-www

COMMENT=	Netmagis web module

RUN_DEPENDS=	netmagis-config:${PORTSDIR}/net-mgmt/netmagis-common \
		dot:${PORTSDIR}/graphics/graphviz \
		pwgen:${PORTSDIR}/sysutils/pwgen \
		tcltls>=1.4.1:${PORTSDIR}/devel/tcltls \
		tDOM>=0.8.0:${PORTSDIR}/www/tdom \
		${LOCALBASE}/share/certs/ca-root-nss.crt:${PORTSDIR}/security/ca_root_nss

NO_ARCH=	# no
USE_TEX=	full

MASTERDIR=	${.CURDIR}/../netmagis-common

PKGMESSAGE=	${.CURDIR}/pkg-message
PLIST=		${.CURDIR}/pkg-plist

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/htgtcl

.include "${MASTERDIR}/Makefile"
