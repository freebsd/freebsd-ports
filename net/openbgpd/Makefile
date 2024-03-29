PORTNAME=	openbgpd
PORTVERSION=	5.2.20121209
PORTREVISION=	5
PORTEPOCH=	1
CATEGORIES=	net
MASTER_SITES=	OPENBSD/OpenBGPD
DISTNAME=	${PORTNAME}-4.6
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Free implementation of the Border Gateway Protocol, Version 4
WWW=		https://www.openbgpd.org/

LICENSE=	ISCL
LICENSE_FILE=	${FILESDIR}/COPYING

USES=		tar:tgz uidfix
USE_RC_SUBR=	${PORTNAME}

CONFLICTS=	zebra quagga

NO_WRKSUBDIR=	yes
PLIST_FILES=	sbin/bgpctl sbin/bgpd share/man/man5/bgpd.conf.5.gz \
		share/man/man8/bgpctl.8.gz share/man/man8/bgpd.8.gz
SUB_FILES=	pkg-message
USERS=		_bgpd
GROUPS=		_bgpd

CFLAGS=		-fcommon

OPTIONS_DEFINE=	IPV6LLPEER
OPTIONS_DEFAULT=IPV6LLPEER
IPV6LLPEER_DESC=Support nexthop using IPv6 link-local address
IPV6LLPEER_MAKE_ARGS=	-DIPV6_LINKLOCAL_PEER

post-patch:
	@${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|g"	\
	    ${WRKSRC}/bgpd/bgpd.8			\
	    ${WRKSRC}/bgpd/bgpd.conf.5			\
	    ${WRKSRC}/bgpctl/bgpctl.8

.include <bsd.port.mk>
