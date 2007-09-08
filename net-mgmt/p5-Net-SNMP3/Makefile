# New ports collection makefile for:	p5-Net-SNMP3
# Date created:				2 oct 2003
# Whom:					Lars Thegler <lars@thegler.dk>
#
# $FreeBSD$
#

PORTNAME=	Net-SNMP
PORTVERSION=	3.65
CATEGORIES=	net-mgmt perl5
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	krion
PKGNAMEPREFIX=	p5-
PKGNAMESUFFIX=	-365

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Net::SNMP for pre-5.6 perl

CONFLICTS=	p5-Net-SNMP
PERL_CONFIGURE=	5.6.0-
USE_PERL5_REASON=	This port is only for pre-5.6 perl. Install net-mgmt/p5-Net-SNMP instead

MAN3=		Net::SNMP.3

DEPRECATED=	only runs with old, unsupported Perl versions
EXPIRATION_DATE=	2007-09-11

.include <bsd.port.mk>
