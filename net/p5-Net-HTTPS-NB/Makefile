PORTNAME=	Net-HTTPS-NB
PORTVERSION=	0.15
CATEGORIES=	net www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Non-blocking HTTPS client

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-IO-Socket-SSL>=0.98:security/p5-IO-Socket-SSL \
		p5-Net-HTTP>=0:net/p5-Net-HTTP

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
