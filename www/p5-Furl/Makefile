PORTNAME=	Furl
PORTVERSION=	3.14
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:TOKUHIROM
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl extension of lightning-fast URL fetcher
WWW=		https://metacpan.org/release/Furl

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Class-Accessor-Lite>=0:devel/p5-Class-Accessor-Lite \
		p5-HTTP-Parser-XS>=0.11:www/p5-HTTP-Parser-XS \
		p5-Mozilla-CA>=0:www/p5-Mozilla-CA
TEST_DEPENDS=	p5-Test-Requires>=0:devel/p5-Test-Requires \
		p5-Test-TCP>=2.11:devel/p5-Test-TCP

USES=		perl5
USE_PERL5=	modbuildtiny

NO_ARCH=	yes

.include <bsd.port.mk>
