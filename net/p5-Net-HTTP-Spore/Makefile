PORTNAME=	Net-HTTP-Spore
PORTVERSION=	0.09
CATEGORIES=	net www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	SPORE client

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Class-Load>=0:devel/p5-Class-Load \
		p5-HTTP-Message>=0:www/p5-HTTP-Message \
		p5-IO-All>=0:devel/p5-IO-All \
		p5-JSON>=0:converters/p5-JSON \
		p5-Moose>=0:devel/p5-Moose \
		p5-MooseX-Role-Parameterized>=1.01:devel/p5-MooseX-Role-Parameterized \
		p5-MooseX-Types>=0:devel/p5-MooseX-Types \
		p5-MooseX-Types-URI>=0:devel/p5-MooseX-Types-URI \
		p5-Try-Tiny>=0:lang/p5-Try-Tiny \
		p5-URI>=0:net/p5-URI \
		p5-XML-Simple>=0:textproc/p5-XML-Simple \
		p5-YAML>=0:textproc/p5-YAML \
		p5-libwww>=0:www/p5-libwww
TEST_DEPENDS=	p5-Test-Exception>=0:devel/p5-Test-Exception

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
