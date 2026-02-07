PORTNAME=	WWW-Shorten-Googl
DISTVERSION=	1.100
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	cowboyneal@gmail.com
COMMENT=	Perl interface to goo.gl
WWW=		https://metacpan.org/release/WWW-Shorten-Googl

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-JSON-Any>=0:converters/p5-JSON-Any \
		p5-libwww>=5.75:www/p5-libwww \
		p5-LWP-Protocol-https>=0:www/p5-LWP-Protocol-https \
		p5-WWW-Shorten>=1.98:www/p5-WWW-Shorten
TEST_DEPENDS=	p5-JSON-MaybeXS>0:converters/p5-JSON-MaybeXS

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
