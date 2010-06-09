# New ports collection makefile for:	instant-server
# Date created:		12 February 2001
# Whom:			grog
#
# $FreeBSD$
#

PORTNAME=	instant-server
PORTVERSION=	1.0
PORTREVISION=	6
CATEGORIES=	misc
MASTER_SITES=	# Empty
DISTFILES=	# None

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Instant server installs a typical set of ports for a server

RUN_DEPENDS=	${LOCALBASE}/sbin/postfix:${PORTSDIR}/mail/postfix \
		${LOCALBASE}/sbin/cvsupd:${PORTSDIR}/net/cvsup \
		${LOCALBASE}/sbin/dhcpd:${PORTSDIR}/net/isc-dhcp41-server \
		${LOCALBASE}/sbin/smbd:${PORTSDIR}/net/samba3 \
		${LOCALBASE}/sbin/traceroute:${PORTSDIR}/net/traceroute \
		cnewsdo:${PORTSDIR}/news/cnews \
		${LOCALBASE}/sbin/squid:${PORTSDIR}/www/squid

# Don't let stupid programs ask for configuration.

BATCH=		YES
USE_APACHE=	1.3
NO_BUILD=	yes

# comms/hylafax irc/ircd-hybrid

postinstall:
	cd ${PORTSDIR}/mail/postfix; make replace

do-install:

.include <bsd.port.mk>
