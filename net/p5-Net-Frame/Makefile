# Created by: Cheng-Lung Sung <clsung@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Net-Frame
PORTVERSION=	1.09
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Base framework for frame crafting

BUILD_DEPENDS=	p5-Bit-Vector>=0:${PORTSDIR}/math/p5-Bit-Vector \
    		p5-Class-Gomor>=1.00:${PORTSDIR}/devel/p5-Class-Gomor \
		p5-Net-IPv6Addr>=0:${PORTSDIR}/net-mgmt/p5-Net-IPv6Addr \
		p5-Socket6>=0:${PORTSDIR}/net/p5-Socket6
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN3=		Net::Frame.3 Net::Frame::Layer.3 \
		Net::Frame::Layer::ARP.3 \
		Net::Frame::Layer::ETH.3 \
		Net::Frame::Layer::IPv4.3 \
		Net::Frame::Layer::NULL.3 \
		Net::Frame::Layer::PPP.3 \
		Net::Frame::Layer::RAW.3 \
		Net::Frame::Layer::SLL.3 \
		Net::Frame::Layer::TCP.3 \
		Net::Frame::Layer::UDP.3

.include <bsd.port.mk>
