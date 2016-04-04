# Created by: Mars G Miro <spry@anarchy.in.the.ph>
# $FreeBSD$

PORTNAME=	Net-Frame-Layer-ICMPv6
PORTVERSION=	1.09
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	spry@anarchy.in.the.ph
COMMENT=	Perl encoding/decoding implementation of the ICMPv6 layer

BUILD_DEPENDS=	p5-Bit-Vector>=0:math/p5-Bit-Vector \
		p5-Net-Frame>=0:net/p5-Net-Frame \
		p5-Net-Pcap>=0.12:net/p5-Net-Pcap \
		p5-Class-Gomor>=1.00:devel/p5-Class-Gomor
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
