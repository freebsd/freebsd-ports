PORTNAME=	Hijk
PORTVERSION=	0.28
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:GUGOD
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Fast & minimal low-level HTTP client

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	p5-HTTP-Server-Simple-PSGI>=0:www/p5-HTTP-Server-Simple-PSGI \
		p5-Net-Server>=0:net/p5-Net-Server \
		p5-Plack>=0:www/p5-Plack \
		p5-Test-Exception>=0:devel/p5-Test-Exception

USES=		perl5
USE_PERL5=	modbuildtiny

NO_ARCH=	yes

.include <bsd.port.mk>
