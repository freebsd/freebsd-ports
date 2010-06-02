# New ports collection makefile for: sdig
# Date created: 25 May 2004
# Whom: Russell A. Jackson <rjackson@cserv62.csub.edu>
#
# $FreeBSD$
#

PORTNAME=	sdig
PORTVERSION=	0.43
PORTREVISION=	4
CATEGORIES=	net-mgmt
MASTER_SITES=	SF

MAINTAINER=	raj@cserv62.csub.edu
COMMENT=	Translate IP/DNS/WINS/MAC address into port description

LIB_DEPENDS=	netsnmp.20:${PORTSDIR}/net-mgmt/net-snmp

USE_GMAKE=	yes
GNU_CONFIGURE=	yes

MAN5=		sdig.conf.5
MAN8=		sdig.8
PLIST_FILES=	bin/sdig etc/sdig.conf-sample etc/mactable-sample

.include <bsd.port.mk>
