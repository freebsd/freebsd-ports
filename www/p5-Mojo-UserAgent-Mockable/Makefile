PORTNAME=	Mojo-UserAgent-Mockable
PORTVERSION=	1.59
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:POPEFELIX
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Mojo User-Agent that can record and play back requests without Internet connectivity
WWW=		https://metacpan.org/dist/Mojo-UserAgent-Mockable

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Class-Load>=0:devel/p5-Class-Load \
		p5-JSON-MaybeXS>=0:converters/p5-JSON-MaybeXS \
		p5-Mojolicious>=7.22:www/p5-Mojolicious \
		p5-Path-Tiny>=0:devel/p5-Path-Tiny \
		p5-Safe-Isa>=0:devel/p5-Safe-Isa \
		p5-Try-Tiny>=0:lang/p5-Try-Tiny
TEST_DEPENDS=	p5-Array-Compare>=0:misc/p5-Array-Compare \
		p5-Devel-Hide>=0:devel/p5-Devel-Hide \
		p5-IO-Socket-SSL>=2.009:security/p5-IO-Socket-SSL \
		p5-Module-Util>=0:devel/p5-Module-Util \
		p5-Mojolicious-Plugin-BasicAuthPlus>=0:www/p5-Mojolicious-Plugin-BasicAuthPlus \
		p5-Moose>=0:devel/p5-Moose \
		p5-Pod-Coverage-TrustPod>=0:devel/p5-Pod-Coverage-TrustPod \
		p5-Test-Exception>=0:devel/p5-Test-Exception \
		p5-Test-JSON>=0:devel/p5-Test-JSON \
		p5-Test-Most>=0:devel/p5-Test-Most \
		p5-Test-Pod>=0:devel/p5-Test-Pod \
		p5-Test-Pod-Coverage>=0:devel/p5-Test-Pod-Coverage

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
