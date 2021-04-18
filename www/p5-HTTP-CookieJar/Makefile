# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	HTTP-CookieJar
PORTVERSION=	0.010
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Minimalist HTTP user agent cookie jar

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-HTTP-Date>=0:www/p5-HTTP-Date
TEST_DEPENDS=	p5-HTTP-Message>=0:www/p5-HTTP-Message \
		p5-Mozilla-PublicSuffix>=0:dns/p5-Mozilla-PublicSuffix \
		p5-Test-Deep>=0:devel/p5-Test-Deep \
		p5-Test-Requires>=0:devel/p5-Test-Requires \
		p5-Test-Simple>=0.96:devel/p5-Test-Simple

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
