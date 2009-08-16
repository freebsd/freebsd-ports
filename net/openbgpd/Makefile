# New ports collection makefile for:	openbgpd
# Date created:				May 10 2005
# Whom:					Florent Thoumie <flz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	openbgpd
PORTVERSION=	4.5.20090709
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_OPENBSD}
MASTER_SITE_SUBDIR=	OpenBGPD
DISTNAME=	${PORTNAME}-4.4.1
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Free implementation of the Border Gateway Protocol, Version 4

CONFLICTS=	zebra-[0-9]* quagga-[0-9]*

OPTIONS=	IPV6LLPEER \
		"Support nexthop using IPv6 link-local address"	on

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 700000
BROKEN=		does not build
.endif

WRKSRC=		${WRKDIR}
MANCOMPRESSED=	yes
USE_RC_SUBR=	${PORTNAME}.sh
PLIST_FILES=	sbin/bgpctl sbin/bgpd
SUB_FILES=	pkg-message

MAN5=		bgpd.conf.5
MAN8=		bgpctl.8 bgpd.8

.if !defined(WITHOUT_IPV6LLPEER)
MAKE_ARGS=	-DIPV6_LINKLOCAL_PEER
.endif

post-patch:
	@${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|g"	\
		${WRKSRC}/bgpd/bgpd.8			\
		${WRKSRC}/bgpd/bgpd.conf.5		\
		${WRKSRC}/bgpctl/bgpctl.8

post-install:
	@${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
