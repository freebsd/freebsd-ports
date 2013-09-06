# New ports collection makefile for:	p5-Net-Analysis
# Date created:		2006-09-05
# Whom:			Jin-Shan Tseng <tjs@cdpa.nsysu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	Net-Analysis
PORTVERSION=	0.41
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	skreuzer@FreeBSD.org
COMMENT=	Modules for analysing network traffic

RUN_DEPENDS=	p5-Net-Pcap>=0:${PORTSDIR}/net/p5-Net-Pcap \
		p5-NetPacket>=0:${PORTSDIR}/net/p5-NetPacket \
		p5-Params-Validate>=0:${PORTSDIR}/devel/p5-Params-Validate \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww
BUILD_DEPENDS:=	${RUN_DEPENDS}
TEST_DEPENDS=	p5-Test-MockObject>=0:${PORTSDIR}/devel/p5-Test-MockObject

USES=		perl5
USE_PERL5=	configure

MAN3=		Net::Analysis.3 \
		Net::Analysis::Constants.3 \
		Net::Analysis::Dispatcher.3 \
		Net::Analysis::EventLoop.3 \
		Net::Analysis::Listener::Base.3 \
		Net::Analysis::Listener::Example1.3 \
		Net::Analysis::Listener::Example2.3 \
		Net::Analysis::Listener::Example3.3 \
		Net::Analysis::Listener::HTTP.3 \
		Net::Analysis::Listener::HTTPPipelining.3 \
		Net::Analysis::Listener::PortCounter.3 \
		Net::Analysis::Listener::TCP.3 \
		Net::Analysis::Packet.3 \
		Net::Analysis::TCPMonologue.3 \
		Net::Analysis::TCPSession.3 \
		Net::Analysis::Time.3

.include <bsd.port.mk>
