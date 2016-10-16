# $FreeBSD$

PORTNAME=	Net-Frame-Device
PORTVERSION=	1.12
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Get network device and gateway information

LICENSE=	ART10

BUILD_DEPENDS=	p5-Net-Write>=1.05:net/p5-Net-Write \
		p5-Net-Frame-Dump>=1.08:net/p5-Net-Frame-Dump \
		p5-Net-Frame-Simple>=1.07:net/p5-Net-Frame-Simple \
		p5-Net-Frame-Layer-IPv6>=1.07:net/p5-Net-Frame-Layer-IPv6 \
		p5-Net-Frame-Layer-ICMPv6>=1.09:net/p5-Net-Frame-Layer-ICMPv6 \
		p5-Net-Libdnet6>=0.27:net/p5-Net-Libdnet6
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
