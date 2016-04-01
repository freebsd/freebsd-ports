# Created by: Pierre David <pdagog@gmail.com>, Jean Benoit <jean@unistra.fr>
# $FreeBSD$

PORTNAME=	netmagis
PKGNAMESUFFIX=	-www

COMMENT=	Netmagis web module

RUN_DEPENDS=	netmagis-config:net-mgmt/netmagis-common \
		dot:graphics/graphviz \
		pwgen:sysutils/pwgen \
		tcltls>=1.4.1:devel/tcltls \
		tDOM>=0.8.0:www/tdom \
		${LOCALBASE}/share/certs/ca-root-nss.crt:security/ca_root_nss

NO_ARCH=	# no
USE_TEX=	full

MASTERDIR=	${.CURDIR}/../netmagis-common

PKGMESSAGE=	${.CURDIR}/pkg-message
PLIST=		${.CURDIR}/pkg-plist

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/htgtcl

.include "${MASTERDIR}/Makefile"
