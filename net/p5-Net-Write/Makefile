PORTNAME=	Net-Write
PORTVERSION=	1.10
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Interface to open and send raw frames to the network
WWW=		https://metacpan.org/release/Net-Write

LICENSE=	ART10
LICENSE_FILE=	${WRKSRC}/LICENSE.Artistic

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Class-Gomor>=1.00:devel/p5-Class-Gomor \
		p5-Socket-GetAddrInfo>=0:net/p5-Socket-GetAddrInfo \
		p5-Net-Pcap>=0.14:net/p5-Net-Pcap

USES=		perl5
USE_PERL5=	configure
NO_ARCH=	yes

.include <bsd.port.mk>
