PORTNAME=	Geo-Calc
PORTVERSION=	0.12
CATEGORIES=	science perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:ASP
PKGNAMEPREFIX=	p5-

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Simple geo calculator for points and distances
WWW=		https://metacpan.org/release/Geo-Calc

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Moose>=0:devel/p5-Moose \
		p5-MooseX-FollowPBP>=0.04:devel/p5-MooseX-FollowPBP \
		p5-MooseX-Method-Signatures>=0.36:devel/p5-MooseX-Method-Signatures \
		p5-Math-BigInt>=1.60:math/p5-Math-BigInt \
		p5-Math-Complex>=1.04:math/p5-Math-Complex \
		p5-Math-Units>=1.3:math/p5-Math-Units

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
