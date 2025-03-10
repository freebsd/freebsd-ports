PORTNAME=	Dancer2-Plugin-Deferred
PORTVERSION=	0.008000
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Dancer2 plugin to defer messages or data across redirections
WWW=		https://metacpan.org/release/Dancer2-Plugin-Deferred

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Dancer2>=0.200000:www/p5-Dancer2 \
		p5-URI>=0:net/p5-URI
TEST_DEPENDS=	p5-HTTP-Cookies>=0:www/p5-HTTP-Cookies \
		p5-HTTP-Message>=0:www/p5-HTTP-Message \
		p5-Plack>=0:www/p5-Plack \
		p5-Test-Simple>=1.302200:devel/p5-Test-Simple

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
