PORTNAME=	Reddit
PORTVERSION=	0.30.03
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Module for interacting with Reddit

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Module-Install>=0:devel/p5-Module-Install \
		p5-Moose>=0:devel/p5-Moose \
		p5-common-sense>=3.2:devel/p5-common-sense
RUN_DEPENDS=	p5-Moose>=0:devel/p5-Moose \
		p5-common-sense>=3.2:devel/p5-common-sense \
		p5-JSON>=2:converters/p5-JSON \
		p5-HTTP-Cookies>=6:www/p5-HTTP-Cookies \
		p5-libwww>=5.829:www/p5-libwww

USES=		perl5
USE_PERL5=	configure
NO_ARCH=	yes

.include <bsd.port.mk>
