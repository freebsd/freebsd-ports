PORTNAME=	netmagis
PORTREVISION=	1
PKGNAMESUFFIX=	-servers

COMMENT=	Netmagis module for dhcp, bind and mail servers

LICENSE=	CECILL-B

RUN_DEPENDS=	netmagis-config:net-mgmt/netmagis-common

MASTERDIR=	${.CURDIR}/../netmagis-common

PKGMESSAGE=	${.CURDIR}/pkg-message
PLIST=		${.CURDIR}/pkg-plist

OPTIONS_DEFINE=	EXAMPLES

.include "${MASTERDIR}/Makefile"
