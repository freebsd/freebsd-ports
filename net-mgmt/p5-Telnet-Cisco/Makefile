# New ports collection makefile for:	p5-Net-Telnet-Cisco
# Date created:			August 16 2001
# Whom:	      			Michael Lyngbøl <lyngbol@wheel.dk>
#
# $FreeBSD$
#

PORTNAME=	Net-Telnet-Cisco
PORTVERSION=	1.10
CATEGORIES=	net-mgmt perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Net
PKGNAMEPREFIX=	p5-

MAINTAINER=	lyngbol@wheel.dk
COMMENT=	Perl5 module to telnet to Cisco routers

RUN_DEPENDS=	${SITE_PERL}/Net/Telnet.pm:${PORTSDIR}/net/p5-Net-Telnet \
		${SITE_PERL}/Test/More.pm:${PORTSDIR}/devel/p5-Test-Simple \
		${SITE_PERL}/${PERL_ARCH}/Term/ReadKey.pm:${PORTSDIR}/devel/p5-Term-ReadKey
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Net::Telnet::Cisco.3

.include <bsd.port.mk>
