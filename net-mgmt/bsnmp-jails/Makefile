# New ports collection makefile for:	bsnmp-jails
# Date created:				12 Dec 2009
# Whom:					dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	bsnmp-jails
PORTVERSION=	0.8
CATEGORIES=	net-mgmt
MASTER_SITES=	http://memberwebs.com/stef/software/bsnmp-jails/

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	A bsnmpd module to measure statistics about jails

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes

MAN8=		bsnmp-jails.8

PLIST_FILES=	lib/snmp_jails.so lib/snmp_jails.so.0 \
		lib/snmp_jails.a lib/snmp_jails.la \
		libexec/jail-measure

.include <bsd.port.mk>
