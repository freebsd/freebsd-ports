# Created by: Jin-Shan Tseng <tjs@cdpa.nsysu.edu.tw>
# $FreeBSD$

PORTNAME=	Net-Analysis
PORTVERSION=	0.41
PORTREVISION=	1
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	skreuzer@FreeBSD.org
COMMENT=	Modules for analysing network traffic

RUN_DEPENDS=	p5-Net-Pcap>=0:net/p5-Net-Pcap \
		p5-NetPacket>=0:net/p5-NetPacket \
		p5-Params-Validate>=0:devel/p5-Params-Validate \
		p5-libwww>=0:www/p5-libwww
BUILD_DEPENDS:=	${RUN_DEPENDS}
TEST_DEPENDS=	p5-Test-MockObject>=0:devel/p5-Test-MockObject

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
