# New ports collection makefile for:	p5-Net-Telnet-Cisco
# Date created:			August 16 2001
# Whom:	      			Michael Lyngbøl <lyngbol@wheel.dk>
#
# $FreeBSD$
#

PORTNAME=	Net-Telnet-Cisco
PORTVERSION=	1.03
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Net
PKGNAMEPREFIX=	p5-

MAINTAINER=	lyngbol@wheel.dk

RUN_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Net/Telnet.pm:${PORTSDIR}/net/p5-Net-Telnet

PERL_CONFIGURE=	yes

MAN3=		Net::Telnet::Cisco.3
MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

.include <bsd.port.mk>
