PORTNAME=	HTML-FromANSI-Tiny
PORTVERSION=	0.107
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Easily convert colored command line output to HTML
WWW=		https://metacpan.org/release/HTML-FromANSI-Tiny

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	p5-HTML-Parser>=0:www/p5-HTML-Parser \
		p5-Parse-ANSIColor-Tiny>=0.600:textproc/p5-Parse-ANSIColor-Tiny
TEST_DEPENDS=	p5-Test-Differences>=0:devel/p5-Test-Differences \
		p5-Test-Requires>=0:devel/p5-Test-Requires

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
