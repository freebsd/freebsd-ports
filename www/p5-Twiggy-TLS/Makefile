PORTNAME=	Twiggy-TLS
PORTVERSION=	0.0020
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:UNDEF
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl extension to extend Twiggy supporting TLS

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-IO-Socket-SSL>=1.62:security/p5-IO-Socket-SSL \
		p5-Plack>=0.99:www/p5-Plack \
		p5-Twiggy>=0.1010:www/p5-Twiggy
TEST_DEPENDS=	p5-LWP-Protocol-https>=6.02:www/p5-LWP-Protocol-https \
		p5-Test-TCP>=0:devel/p5-Test-TCP \
		p5-libwww>=6.00:www/p5-libwww

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
