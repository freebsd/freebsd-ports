# Created by: Jin-Shan Tseng <tjs@cdpa.nsysu.edu.tw>

PORTNAME=	Net-DHCP
PORTVERSION=	0.700
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:S|00$||}

MAINTAINER=	perl@FreeBSD.org
COMMENT=	DHCP set of classes designed to handle basic DHCP handling

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	p5-Net-Frame-Dump>=0:net/p5-Net-Frame-Dump \
		p5-Net-Frame-Simple>=0:net/p5-Net-Frame-Simple \
		p5-Net-Pcap>=0:net/p5-Net-Pcap \
		p5-Test-Warn>=0:devel/p5-Test-Warn

USES=		perl5
USE_PERL5=	modbuild

NO_ARCH=	yes

.include <bsd.port.mk>
