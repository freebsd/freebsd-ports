PORTNAME=	AnyEvent-WebSocket-Client
PORTVERSION=	0.55
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
#MASTER_SITE_SUBDIR=	CPAN:PLICEASE
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	WebSocket client for AnyEvent
WWW=		https://github.com/plicease/AnyEvent-WebSocket-Client

LICENSE=	ART10

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-AnyEvent>=7.13:devel/p5-AnyEvent \
		p5-AnyEvent-Connector>=0.03:devel/p5-AnyEvent-Connector \
		p5-Moo>=2.0:devel/p5-Moo \
		p5-PerlX-Maybe>=0.003:devel/p5-PerlX-Maybe \
		p5-Protocol-WebSocket>=0.20:www/p5-Protocol-WebSocket \
		p5-URI>=1.53:net/p5-URI \
		p5-URI-ws>=0:net/p5-URI-ws
TEST_DEPENDS=	p5-Test-Simple>=1.302200:devel/p5-Test-Simple

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
