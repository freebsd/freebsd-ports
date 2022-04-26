PORTNAME=	LWP-Protocol-PSGI
PORTVERSION=	0.11
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl extension to override LWP HTTP/HTTPS backend with your PSGI app

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Plack>=0:www/p5-Plack \
		p5-libwww>=5:www/p5-libwww
TEST_DEPENDS=	p5-Test-Requires>=0:devel/p5-Test-Requires


USES=		perl5
USE_PERL5=	modbuildtiny

NO_ARCH=	yes

.include <bsd.port.mk>
