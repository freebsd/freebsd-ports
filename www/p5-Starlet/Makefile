PORTNAME=	Starlet
PORTVERSION=	0.31
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:KAZUHO
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl extension for standalone HTTP/1.0 server

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Parallel-Prefork>=0.17:devel/p5-Parallel-Prefork \
		p5-Plack>=0.9920:www/p5-Plack \
		p5-Server-Starter>=0.06:net/p5-Server-Starter
TEST_DEPENDS=	p5-Test-TCP>=2.10:devel/p5-Test-TCP \
		p5-libwww>=5.80:www/p5-libwww

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
