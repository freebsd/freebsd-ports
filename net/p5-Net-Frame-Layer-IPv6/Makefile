# New ports collection makefile for:	Net-Frame-IPv6
# Date created:	   09 Mar 2009
# Whom:		   Mars G Miro <spry@anarchy.in.the.ph>
#
# $FreeBSD$
#

PORTNAME=	Net-Frame-Layer-IPv6
PORTVERSION=	1.02
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	spry@anarchy.in.the.ph
COMMENT=	Perl encoding/decoding implementation of the IPv6 layer

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Bit/Vector.pm:${PORTSDIR}/math/p5-Bit-Vector \
		${SITE_PERL}/Net/Frame.pm:${PORTSDIR}/net/p5-Net-Frame \
    		p5-Net-Pcap>=0.12:${PORTSDIR}/net/p5-Net-Pcap \
    		p5-Class-Gomor>=1.00:${PORTSDIR}/devel/p5-Class-Gomor
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Net::Frame::Layer::IPv6.3

.include <bsd.port.mk>
