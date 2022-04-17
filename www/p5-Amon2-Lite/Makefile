PORTNAME=	Amon2-Lite
PORTVERSION=	0.13
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl extension for Sinatra-ish framework on Amon2!

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Amon2-Plugin-Web-CSRFDefender>=0:www/p5-Amon2-Plugin-Web-CSRFDefender \
		p5-Amon2>=3.25:www/p5-Amon2 \
		p5-Plack>=0:www/p5-Plack \
		p5-Plack-Middleware-Session>=0:www/p5-Plack-Middleware-Session \
		p5-Router-Simple>=0.13:www/p5-Router-Simple \
		p5-Text-Xslate-Bridge-TT2Like>=0.00010:textproc/p5-Text-Xslate-Bridge-TT2Like \
		p5-Text-Xslate>=2.0010:textproc/p5-Text-Xslate
TEST_DEPENDS=	p5-HTTP-Message>=0:www/p5-HTTP-Message \
		p5-Test-Requires>=0:devel/p5-Test-Requires \
		p5-Test-WWW-Mechanize>=0:devel/p5-Test-WWW-Mechanize \
		p5-Tiffany>=0:textproc/p5-Tiffany

USES=		perl5
USE_PERL5=	modbuild

NO_ARCH=	yes

.include <bsd.port.mk>
