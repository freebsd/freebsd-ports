PORTNAME=	Net-Async-XMPP
PORTVERSION=	0.003
PORTREVISION=	3
CATEGORIES=	net-im perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Asynchronous XMPP client and server

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Future>=0.29:devel/p5-Future \
		p5-IO-Async>=0.60:devel/p5-IO-Async \
		p5-IO-Async-Resolver-DNS>=0.04:dns/p5-IO-Async-Resolver-DNS \
		p5-IO-Async-SSL>=0.14:security/p5-IO-Async-SSL \
		p5-Mixin-Event-Dispatch>=1:devel/p5-Mixin-Event-Dispatch \
		p5-Protocol-XMPP>=0.006:net-im/p5-Protocol-XMPP \
		p5-curry>=0:devel/p5-curry
TEST_DEPENDS=	p5-Test-CheckDeps>=0.010:devel/p5-Test-CheckDeps \
		p5-Test-Fatal>=0.010:devel/p5-Test-Fatal

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
