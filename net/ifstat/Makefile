# New ports collection makefile for:   ifstat
# Date created:                30 Mar 2003
# Whom:                        spf@xslt.cs.nccu.edu.tw
#
# $FreeBSD$
#

PORTNAME=	ifstat
PORTVERSION=	1.1
CATEGORIES=	net
MASTER_SITES=	http://gael.roualland.free.fr/%SUBDIR%/
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	krion@FreeBSD.org
COMMENT=	Network interface statistics monitoring tool

LIB_DEPENDS=	netsnmp.6:${PORTSDIR}/net/net-snmp

USE_SIZE=	yes
GNU_CONFIGURE=	yes
USE_OPENSSL=	yes

MAN1=		ifstat.1
PLIST_FILES=	bin/ifstat

.include <bsd.port.mk>
