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
PERL_CONFIGURE=	yes

MAN3=		Net::SNMP.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} >= 500600
IGNORE=	This port is only for pre-5.6 perl. Install net-mgmt/p5-Net-SNMP instead.
.endif

.include <bsd.port.post.mk>
