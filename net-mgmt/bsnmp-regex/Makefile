# New ports collection makefile for:	bsnmp-regex
# Date created:				11 February 2007
# Whom:					brock@cotcomsol.com
#
# $FreeBSD$
#

PORTNAME=	bsnmp-regex
PORTVERSION=	0.3
CATEGORIES=	net-mgmt
MASTER_SITES=	http://memberwebs.com/stef/software/bsnmp-regex/

MAINTAINER=	brock@cotcomsol.com
COMMENT=	A bsnmpd module allowing creation of counters from log files

HAS_CONFIGURE=	yes
CONFIGURE_ARGS+=	--mandir=${MANPREFIX}/man

MAN1=		sockin.1
MAN5=		bsnmp-regex.conf.5
MAN8=		bsnmp-regex.8

PLIST_FILES=	bin/sockin lib/snmp_regex.so lib/snmp_regex.so.0 \
		lib/snmp_regex.a lib/snmp_regex.la

.include <bsd.port.mk>
