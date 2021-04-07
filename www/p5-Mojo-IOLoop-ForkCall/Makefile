PORTNAME=		Mojo-IOLoop-ForkCall
PORTVERSION=		0.21
CATEGORIES=		www perl5
MASTER_SITES=		CPAN
MASTER_SITE_SUBDIR=	CPAN:JBERGER
PKGNAMEPREFIX=		p5-

MAINTAINER=		olgeni@FreeBSD.org
COMMENT=		Run blocking functions asynchronously by forking

LICENSE=		ART10 GPLv1+
LICENSE_COMB=		dual

RUN_DEPENDS=		p5-Mojolicious>=5.08:www/p5-Mojolicious \
			p5-IO-Pipely>=0.005:devel/p5-IO-Pipely \
			p5-Perl-OSType>=0:devel/p5-Perl-OSType \
			p5-Mojo-IOLoop-Delay>=8.76:www/p5-Mojo-IOLoop-Delay

USES=			perl5
USE_PERL5=		modbuild
PL_BUILD=		Build

.include <bsd.port.mk>
