# New ports collection makefile for:   p5-Net-DHCP
# Date created:                2006-07-13
# Whom:                        Jin-Shan Tseng <tjs@cdpa.nsysu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	Net-DHCP
PORTVERSION=	0.66
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Net
PKGNAMEPREFIX=	p5-

MAINTAINER=	tjs@cdpa.nsysu.edu.tw
COMMENT=	A DHCP set of classes designed to handle basic DHCP handling

PERL_CONFIGURE=	yes

MAN3=		Net::DHCP::Packet.3 Net::DHCP::Constants.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800
IGNORE=		requires perl 5.8.0 or later. Install lang/perl5.8 then try again
.endif

.include <bsd.port.post.mk>
