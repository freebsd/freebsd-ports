PORTNAME=	AnyEvent-WebSocket-Client
PORTVERSION=	0.55
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:PLICEASE
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	WebSocket client for AnyEvent
WWW=		https://github.com/plicease/AnyEvent-WebSocket-Client

LICENSE=	ART10

BUILD_DEPENDS=	p5-AnyEvent>0:devel/p5-AnyEvent \
		p5-Test2-Suite>0:devel/p5-Test2-Suite
RUN_DEPENDS:=	p5-AnyEvent>0:devel/p5-AnyEvent \
		p5-Moo>0:devel/p5-Moo \
		p5-PerlX-Maybe>0:devel/p5-PerlX-Maybe \
		p5-Protocol-WebSocket>0:www/p5-Protocol-WebSocket \
		p5-URI-ws>0:net/p5-URI-ws \
		p5-URI>0:net/p5-URI

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
