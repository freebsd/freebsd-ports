# New ports collection makefile for: sdig
# Date created: 25 May 2004
# Whom: Russell A. Jackson <rjackson@cserv62.csub.edu>
#
# $FreeBSD$
#

PORTNAME=	sdig
PORTVERSION=	0.40
CATEGORIES=	net-mgmt
MASTER_SITES=	http://www.exploits.org/sdig/

MAINTAINER=	rjackson@cserv62.csub.edu
COMMENT=	Find which switch/router port a given host is on

LIB_DEPENDS=	netsnmp.6:${PORTSDIR}/net-mgmt/net-snmp

USE_GMAKE=	yes
GNU_CONFIGURE=	yes

MAN5=		sdig.conf.5
MAN8=		sdig.8
PLIST_FILES=	bin/sdig etc/sdig.conf-sample

.include <bsd.port.mk>
