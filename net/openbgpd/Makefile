# $FreeBSD$

PORTNAME=	openbgpd
PORTVERSION=	5.2.20121209
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_OPENBSD}
MASTER_SITE_SUBDIR=	OpenBGPD
DISTNAME=	${PORTNAME}-4.6
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Free implementation of the Border Gateway Protocol, Version 4

CONFLICTS=	zebra-[0-9]* quagga-[0-9]*

WRKSRC=		${WRKDIR}
USE_RC_SUBR=	${PORTNAME}
PLIST_FILES=	sbin/bgpctl sbin/bgpd man/man5/bgpd.conf.5.gz \
		man/man8/bgpctl.8.gz man/man8/bgpd.8.gz
SUB_FILES=	pkg-message
USERS=		_bgpd
GROUPS=		_bgpd

OPTIONS_DEFINE=	IPV6LLPEER
OPTIONS_DEFAULT=IPV6LLPEER
IPV6LLPEER_DESC=Support nexthop using IPv6 link-local address

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MIPV6LLPEER}
MAKE_ARGS=	-DIPV6_LINKLOCAL_PEER
.endif

post-patch:
	@${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|g"	\
		${WRKSRC}/bgpd/bgpd.8			\
		${WRKSRC}/bgpd/bgpd.conf.5		\
		${WRKSRC}/bgpctl/bgpctl.8

.include <bsd.port.mk>
