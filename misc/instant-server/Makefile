# New ports collection makefile for:	instant-server
# Date created:		12 February 2001
# Whom:			grog
#
# $FreeBSD$
#

PORTNAME=	instant-server
PORTVERSION=	1.0
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.lemis.com/pub/
MASTER_SITE_SUBDIR=	pub/instant-server

MAINTAINER=	grog@lemis.com

RUN_DEPENDS=	${LOCALBASE}/sbin/postfix:${PORTSDIR}/mail/postfix \
		cvsupd:${PORTSDIR}/net/cvsupd-bin \
		isc-dhcp3:${PORTSDIR}/net/isc-dhcp3 \
		samba:${PORTSDIR}/net/samba \
		traceroute:${PORTSDIR}/net/traceroute \
		cnews:${PORTSDIR}/news/cnews \
		apache13:${PORTSDIR}/www/apache13 \
		squid23:${PORTSDIR}/www/squid23

# Don't let stupid programs ask for configuration.

BATCH=		YES
NO_WRKSUBDIR=	YES

# comms/hylafax irc/ircd-hybrid

postinstall:
	cd ${PORTSDIR}/mail/postfix; make replace

.include <bsd.port.mk>
