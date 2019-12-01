# $FreeBSD$

PORTNAME=	openbgpd
PORTVERSION=	6.6p0
CATEGORIES=	net
MASTER_SITES=	OPENBSD/OpenBGPD
PKGNAMESUFFIX=	6

MAINTAINER=	pi@FreeBSD.org
COMMENT=	Free implementation of the Border Gateway Protocol, Version 4

LICENSE=	ISCL
LICENSE_FILE=	${FILESDIR}/COPYING

USES=		autoreconf libtool uidfix
USE_RC_SUBR=	${PORTNAME}

GNU_CONFIGURE=	yes

SUB_FILES=	pkg-message

USERS=		_bgpd
GROUPS=		_bgpd

CONFLICTS=	zebra-[0-9]* quagga-[0-9]*

OPTIONS_DEFINE=		IPV6LLPEER
OPTIONS_DEFAULT=	IPV6LLPEER
IPV6LLPEER_DESC=	Support nexthop using IPv6 link-local address
IPV6LLPEER_MAKE_ARGS=	-DIPV6_LINKLOCAL_PEER

.include <bsd.port.mk>
