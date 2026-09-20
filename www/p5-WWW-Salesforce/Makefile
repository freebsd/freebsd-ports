PORTNAME=	WWW-Salesforce
PORTVERSION=	0.401
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
MASTER_SITE_SUBDIR=  CPAN:CAPOEIRAB

MAINTAINER=	matthew@FreeBSD.org
COMMENT=	Simple abstraction layer between SOAP::Lite and Salesforce.com
WWW=		https://metacpan.org/release/WWW-Salesforce

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-SOAP-Lite>=1.0:net/p5-SOAP-Lite \
		p5-IO-Socket-SSL>=1.94:security/p5-IO-Socket-SSL \
		p5-JSON-MaybeXS>=1.0:converters/p5-JSON-MaybeXS \
		p5-LWP-Protocol-https>=6.00:www/p5-LWP-Protocol-https \
		p5-DateTime>=0:devel/p5-DateTime
TEST_DEPENDS=	p5-Test-Pod>=0:devel/p5-Test-Pod \
		p5-Test-Pod-Coverage>=0:devel/p5-Test-Pod-Coverage

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	modbuildtiny

.include <bsd.port.mk>
