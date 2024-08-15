PORTNAME=	Net-Async-HTTP
PORTVERSION=	0.49
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Use HTTP with IO::Async
WWW=		https://metacpan.org/release/Net-Async-HTTP

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Future>=0.28:devel/p5-Future \
		p5-HTTP-Cookies>=0:www/p5-HTTP-Cookies \
		p5-HTTP-Message>=0:www/p5-HTTP-Message \
		p5-IO-Async>=0.59:devel/p5-IO-Async \
		p5-Metrics-Any>=0.05:devel/p5-Metrics-Any \
		p5-Struct-Dumb>=0.07:devel/p5-Struct-Dumb \
		p5-URI>=0:net/p5-URI
TEST_DEPENDS=	p5-IO-Async-SSL>=0.12:security/p5-IO-Async-SSL \
		p5-Test-Metrics-Any>=0:devel/p5-Test-Metrics-Any \
		p5-Test-Simple>=1.302200:devel/p5-Test-Simple

USES=		perl5
USE_PERL5=	modbuild

NO_ARCH=	yes

OPTIONS_DEFINE=	SSL

SSL_BUILD_DEPENDS=	p5-IO-Async-SSL>=0.12:security/p5-IO-Async-SSL
SSL_RUN_DEPENDS=	p5-IO-Async-SSL>=0.12:security/p5-IO-Async-SSL

.include <bsd.port.mk>
