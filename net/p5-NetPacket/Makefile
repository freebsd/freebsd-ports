# New ports collection makefile for:	p5-NetPacket
# Date created:				8 April 2001
# Whom:					Anatoliy Dmytriyev
#
# $FreeBSD$
#

PORTNAME=	NetPacket
PORTVERSION=	0.03
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	NetPacket
PKGNAMEPREFIX=	p5-

MAINTAINER=	tolid@plab.ku.dk

PERL_CONFIGURE=	yes

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=	NetPacket.3 NetPacket::ARP.3 NetPacket::Ethernet.3 NetPacket::ICMP.3 \
	NetPacket::IGMP.3 NetPacket::IP.3 NetPacket::TCP.3 NetPacket::UDP.3

.include <bsd.port.mk>
