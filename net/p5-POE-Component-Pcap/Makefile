# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	POE-Component-Pcap
PORTVERSION=	0.04
PORTREVISION=	1
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	POE component for non-blocking use of Net::Pcap

BUILD_DEPENDS=	p5-POE>=0:devel/p5-POE \
		p5-Net-Pcap>=0:net/p5-Net-Pcap \
		p5-NetPacket>=0:net/p5-NetPacket
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
