PORTNAME=	Catalyst-Controller-RateLimit
PORTVERSION=	0.28
PORTREVISION=	2
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Protect your site from robots

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Algorithm-FloodControl>=1.91:devel/p5-Algorithm-FloodControl \
		p5-Catalyst-Plugin-Cache-FastMmap>=0:www/p5-Catalyst-Plugin-Cache-FastMmap \
		p5-Catalyst-Plugin-ConfigLoader>=0:www/p5-Catalyst-Plugin-ConfigLoader \
		p5-Catalyst-Runtime>=5.7002:www/p5-Catalyst-Runtime \
		p5-Params-Validate>=0:devel/p5-Params-Validate
TEST_DEPENDS=	p5-Test-WWW-Mechanize-Catalyst>=0:devel/p5-Test-WWW-Mechanize-Catalyst \
		p5-Class-Data-Inheritable>=0:devel/p5-Class-Data-Inheritable

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
