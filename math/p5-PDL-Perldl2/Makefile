PORTNAME=	PDL-Perldl2
PORTVERSION=	2.002
CATEGORIES=	math perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Simple shell (version 2) for PDL
WWW=		https://metacpan.org/dist/PDL-Perldl2

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Devel-REPL>=0:devel/p5-Devel-REPL \
		p5-PDL>=2.095:math/p5-PDL \
		p5-namespace-clean>=0:devel/p5-namespace-clean

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
