# New ports collection makefile for:   ifstat
# Date created:                30 Mar 2003
# Whom:                        spf@xslt.cs.nccu.edu.tw
#
# $FreeBSD$
#

PORTNAME=	ifstat
PORTVERSION=	1.1
PORTREVISION=	4
CATEGORIES=	net
MASTER_SITES=	http://gael.roualland.free.fr/%SUBDIR%/
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	alexey@renatasystems.org
COMMENT=	Network interface statistics monitoring tool

GNU_CONFIGURE=	yes
USE_OPENSSL=	yes

OPTIONS=	SNMP "SNMP support" off

MAN1=		ifstat.1
PLIST_FILES=	bin/ifstat

.include <bsd.port.pre.mk>

.if defined(WITH_SNMP)
LIB_DEPENDS+=	netsnmp.20:${PORTSDIR}/net-mgmt/net-snmp
.else
CONFIGURE_ARGS+=	--without-snmp
.endif

.include <bsd.port.post.mk>
