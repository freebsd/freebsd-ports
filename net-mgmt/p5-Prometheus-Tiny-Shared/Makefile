PORTNAME=	Prometheus-Tiny-Shared
PORTVERSION=	0.027
CATEGORIES=	net-mgmt perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	nork@FreeBSD.org
COMMENT=	Tiny Prometheus client with a shared database behind it
WWW=		https://metacpan.org/release/Prometheus-Tiny-Shared

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

RUN_DEPENDS=	p5-Hash-SharedMem>0:devel/p5-Hash-SharedMem \
		p5-JSON-XS>0:converters/p5-JSON-XS \
		p5-Prometheus-Tiny>=0.011:net-mgmt/p5-Prometheus-Tiny
TEST_DEPENDS=	p5-Data-Random>0:devel/p5-Data-Random \
		p5-Test-Differences>0:devel/p5-Test-Differences \
		p5-Test-Exception>0:devel/p5-Test-Exception \
		p5-Test-Warn>0:devel/p5-Test-Warn
#		p5-HTTP-Request-Common>0:p5-HTTP-Request-Common \
#		p5-Plack-Test>0:p5-Plack-Test \

USES=		perl5
USE_PERL5=	configure

TEST_ENV=	# RELEASE_TESTING=1 #: release test not work #

NO_ARCH=	yes
NO_TEST=	yes # almost work, but not by a lack of some ports #

PLIST_FILES=	${SITE_MAN3_REL}/Prometheus::Tiny::Shared.3.gz \
		${SITE_PERL_REL}/Prometheus/Tiny/Shared.pm

.include <bsd.port.mk>
