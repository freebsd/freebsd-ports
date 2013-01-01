# New ports collection makefile for:	instant-server
# Date created:		12 February 2001
# Whom:			grog
#
# $FreeBSD$
#

PORTNAME=	instant-server
PORTVERSION=	1.0
PORTREVISION=	10
CATEGORIES=	misc
MASTER_SITES=	# Empty
DISTFILES=	# None

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Instant server installs a typical set of ports for a server

RUN_DEPENDS=	${LOCALBASE}/sbin/postfix:${PORTSDIR}/mail/postfix \
		${LOCALBASE}/sbin/dhcpd:${PORTSDIR}/net/isc-dhcp41-server \
		${LOCALBASE}/sbin/smbd:${PORTSDIR}/${SAMBA_PORT} \
		${LOCALBASE}/sbin/traceroute:${PORTSDIR}/net/traceroute \
		cnewsdo:${PORTSDIR}/news/cnews \
		${LOCALBASE}/sbin/squid:${PORTSDIR}/www/squid

SAMBA_PORT?=	net/samba34

# Don't let stupid programs ask for configuration.

BATCH=		YES
USE_APACHE_RUN=	22+
NO_BUILD=	yes

# comms/hylafax irc/ircd-hybrid

do-install:

.include <bsd.port.mk>
