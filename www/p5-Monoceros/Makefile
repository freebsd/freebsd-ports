PORTNAME=	Monoceros
PORTVERSION=	0.29
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:KAZEBURO
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	PSGI/Plack server w/ event driven connection manager, prefork workers
WWW=		https://metacpan.org/release/Monoceros

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-AnyEvent>=7.04,1:devel/p5-AnyEvent \
		p5-IO-FDPass>=1.0:devel/p5-IO-FDPass \
		p5-Net-CIDR-Lite>=0:net/p5-Net-CIDR-Lite \
		p5-POSIX-getpeername>=0:net/p5-POSIX-getpeername \
		p5-Parallel-Prefork>=0.14:devel/p5-Parallel-Prefork \
		p5-Plack>=1.0035:www/p5-Plack \
		p5-Starlet>=0.18:www/p5-Starlet
TEST_DEPENDS=	p5-Test-TCP>=2.00:devel/p5-Test-TCP \
		p5-libwww>=0:www/p5-libwww

USES=		perl5
USE_PERL5=	modbuildtiny

NO_ARCH=	yes

.include <bsd.port.mk>
