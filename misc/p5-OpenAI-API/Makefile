PORTNAME=	OpenAI-API
PORTVERSION=	0.37
CATEGORIES=	misc perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:NFERRAZ
PKGNAMEPREFIX=	p5-

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Perl interface to OpenAI API
WWW=		https://metacpan.org/release/OpenAI-API

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-JSON-MaybeXS>=0:converters/p5-JSON-MaybeXS \
		p5-Moo>=2.005005:devel/p5-Moo \
		p5-Type-Tiny>=2.002001:devel/p5-Type-Tiny \
		p5-libwww>=6.47:www/p5-libwww \
		p5-namespace-clean>=0.27:devel/p5-namespace-clean \
		p5-strictures>=2.000006:devel/p5-strictures
TEST_DEPENDS=	p5-Test-Deep>=0:devel/p5-Test-Deep \
		p5-Test-Exception>=0:devel/p5-Test-Exception \
		p5-Test-RequiresInternet>=0:devel/p5-Test-RequiresInternet

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
