# New ports collection makefile for: mcast-tools
# Date created:  15 Sep 2005
# Whom:   suz
#
# $FreeBSD$
#

PORTNAME=	mcast-tools
PORTVERSION=	20061214
PORTREVISION=	0
CATEGORIES=	net ipv6
MASTER_SITES=	SF

MAINTAINER=	suz@FreeBSD.org
COMMENT=	IPv6 multicast routing daemons and tools

GNU_CONFIGURE=	yes

CONFIGURE_ARGS=
CONFIGURE_ENV=

MAN1=		mcastread.1 mcastsend.1 pim6stat.1 pmsft.1
MAN5=		pim6dd.conf.5 pim6sd.conf.5
MAN8=		mfc.8 mtrace6.8 pim6dd.8 pim6sd.8

post-install:
	${INSTALL_DATA} ${WRKSRC}/pim6sd/pim6sd.conf.sample ${PREFIX}/etc
	${INSTALL_DATA} ${FILESDIR}/pim6dd.conf.sample ${PREFIX}/etc
	${INSTALL_DATA} ${WRKSRC}/mfc/mfc.conf.sample ${PREFIX}/etc

.include <bsd.port.mk>
