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
		${LOCALBASE}/sbin/cvsupd:${PORTSDIR}/net/cvsupd-bin \
		${LOCALBASE}/sbin/dhcpd:${PORTSDIR}/net/isc-dhcp3 \
		${LOCALBASE}/sbin/smbd:${PORTSDIR}/net/samba \
		${LOCALBASE}/sbin/traceroute:${PORTSDIR}/net/traceroute \
		cnewsdo:${PORTSDIR}/news/cnews \
		${LOCALBASE}/sbin/httpd:${PORTSDIR}/www/apache13 \
		${LOCALBASE}/sbin/squid:${PORTSDIR}/www/squid23

# Don't let stupid programs ask for configuration.

BATCH=		YES
NO_WRKSUBDIR=	YES

# comms/hylafax irc/ircd-hybrid

postinstall:
	cd ${PORTSDIR}/mail/postfix; make replace

.include <bsd.port.mk>
