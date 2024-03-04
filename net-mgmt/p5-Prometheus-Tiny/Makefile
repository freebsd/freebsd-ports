PORTNAME=	Prometheus-Tiny
PORTVERSION=	0.011
CATEGORIES=	net-mgmt perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	nork@FreeBSD.org
COMMENT=	Tiny Prometheus client
WWW=		https://metacpan.org/release/Prometheus-Tiny

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

#TEST_DEPENDS=	p5-HTTP-Request-Common>0:p5-HTTP-Request-Common \
#		p5-Plack-Test>0:p5-Plack-Test \
#		p5-Test-Exception>0:devel/p5-Test-Exception \
#		p5-Test-Warn>0:devel/p5-Test-Warn

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes
NO_TEST=	yes # not work by a lack of some ports #

PLIST_FILES=	${SITE_MAN3_REL}/Prometheus::Tiny.3.gz \
		${SITE_PERL_REL}/Prometheus/Tiny.pm

.include <bsd.port.mk>
