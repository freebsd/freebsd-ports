# New ports collection makefile for:	openbgpd
# Date created:				May 10 2005
# Whom:					Florent Thoumie <flz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	openbgpd
PORTVERSION=	4.4.1
PORTREVISION=	2
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_OPENBSD}
MASTER_SITE_SUBDIR=	OpenBGPD
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	openbgpd

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Free implementation of the Border Gateway Protocol, Version 4

CONFLICTS=	zebra-[0-9]* quagga-[0-9]*

WRKSRC=		${WRKDIR}
MANCOMPRESSED=	yes
USE_RC_SUBR=	openbgpd.sh
PLIST_FILES=	sbin/bgpctl sbin/bgpd
SUB_FILES=	pkg-message

MAN5=		bgpd.conf.5
MAN8=		bgpctl.8 bgpd.8

post-patch:
	@${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|g"	\
		${WRKSRC}/bgpd/bgpd.8			\
		${WRKSRC}/bgpd/bgpd.h			\
		${WRKSRC}/bgpd/bgpd.conf.5		\
		${WRKSRC}/bgpctl/bgpctl.8

post-install:
	@${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
