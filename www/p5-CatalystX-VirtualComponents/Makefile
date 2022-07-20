PORTNAME=	CatalystX-VirtualComponents
PORTVERSION=	0.00004
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	danny@dannywarren.com
COMMENT=	Setup virtual Catalyst components

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-namespace-clean>0:devel/p5-namespace-clean \
		p5-Catalyst-Runtime>=5.8:www/p5-Catalyst-Runtime \
		p5-Devel-InheritNamespace>0:devel/p5-Devel-InheritNamespace \
		p5-Moose>0:devel/p5-Moose \
		p5-Module-Pluggable>0:devel/p5-Module-Pluggable

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
