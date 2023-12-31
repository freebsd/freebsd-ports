PORTNAME=	netmagis
PORTREVISION=	1
PKGNAMESUFFIX=	-topo

COMMENT=	Netmagis topology module

LICENSE=	CECILL-B

RUN_DEPENDS=	netmagis-config:net-mgmt/netmagis-common \
		rancid-run:net-mgmt/rancid3 \
		fping:net/fping

USE_RC_SUBR=	topographd toposendd
SUB_LIST=	TCLSH=${TCLSH}

MASTERDIR=	${.CURDIR}/../netmagis-common

FILESDIR=	${.CURDIR}/files
PKGMESSAGE=	${.CURDIR}/pkg-message
PLIST=		${.CURDIR}/pkg-plist

ALL_TARGET=build${PKGNAMESUFFIX?=}

OPTIONS_DEFINE=	EXAMPLES

post-install:
	@${MKDIR} ${STAGEDIR}/var/netmagis/eqgen ${STAGEDIR}/var/netmagis/eqvirt

.include "${MASTERDIR}/Makefile"
