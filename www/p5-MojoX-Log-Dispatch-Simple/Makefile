PORTNAME=	MojoX-Log-Dispatch-Simple
DISTVERSION=	1.15
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	bokutin@bokut.in
COMMENT=	Simple Log::Dispatch replacement of Mojo::Log
WWW=		https://metacpan.org/release/MojoX-Log-Dispatch-Simple

LICENSE=	ARTPERL10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

_BR_DEPENDS=	p5-Log-Dispatch>=0:devel/p5-Log-Dispatch \
		p5-Mojolicious>=0:www/p5-Mojolicious
BUILD_DEPENDS=	${_BR_DEPENDS}
RUN_DEPENDS=	${_BR_DEPENDS}
TEST_DEPENDS=	p5-Test-Most>=0:devel/p5-Test-Most

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
