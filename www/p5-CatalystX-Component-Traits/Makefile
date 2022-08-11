PORTNAME=	CatalystX-Component-Traits
PORTVERSION=	0.19
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	des@FreeBSD.org
COMMENT=	Automatic Trait Loading and Resolution for Catalyst Components

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Catalyst-Runtime>=5.80005:www/p5-Catalyst-Runtime \
		p5-List-MoreUtils>=0:lang/p5-List-MoreUtils \
		p5-MooseX-Traits-Pluggable>=0.08:devel/p5-MooseX-Traits-Pluggable \
		p5-namespace-autoclean>=0:devel/p5-namespace-autoclean

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
