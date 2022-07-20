PORTNAME=	Net-Frame
PORTVERSION=	1.21
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Base framework for frame crafting

LICENSE=	ART10
LICENSE_FILE=	${WRKSRC}/LICENSE.Artistic

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Bit-Vector>=0:math/p5-Bit-Vector \
		p5-Class-Gomor>=1.00:devel/p5-Class-Gomor \
		p5-Net-IPv6Addr>=0:net-mgmt/p5-Net-IPv6Addr \
		p5-Socket6>=0:net/p5-Socket6

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
