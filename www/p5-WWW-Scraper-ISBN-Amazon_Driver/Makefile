PORTNAME=	WWW-Scraper-ISBN-Amazon_Driver
PORTVERSION=	1.00
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Search driver for the (US) Amazon online catalog

LICENSE=	ART20

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-WWW-Mechanize>=1.60:www/p5-WWW-Mechanize \
		p5-WWW-Scraper-ISBN>=1:www/p5-WWW-Scraper-ISBN
TEST_DEPENDS=	p5-JSON>=0:converters/p5-JSON \
		p5-Test-MockModule>=0:devel/p5-Test-MockModule

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
