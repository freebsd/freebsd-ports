# Created by: Cheng-Lung Sung <clsung@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Net-Frame-Dump
PORTVERSION=	1.13
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Tcpdump like perl implementation

LICENSE=	ART10

BUILD_DEPENDS=	p5-Bit-Vector>=0:${PORTSDIR}/math/p5-Bit-Vector \
		p5-Net-Frame>=0:${PORTSDIR}/net/p5-Net-Frame \
    		p5-Net-Pcap>=0.12:${PORTSDIR}/net/p5-Net-Pcap \
    		p5-Class-Gomor>=1.00:${PORTSDIR}/devel/p5-Class-Gomor
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
