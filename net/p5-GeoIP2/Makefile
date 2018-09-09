# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	GeoIP2
PORTVERSION=	2.006001
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:MAXMIND
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Perl API for MaxMind GeoIP2 web services and databases

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Data-Validate-IP>=0.25:net-mgmt/p5-Data-Validate-IP \
		p5-HTTP-Message>=0:www/p5-HTTP-Message \
		p5-JSON-MaybeXS>=0:converters/p5-JSON-MaybeXS \
		p5-LWP-Protocol-https>=0:www/p5-LWP-Protocol-https \
		p5-List-SomeUtils>=0:devel/p5-List-SomeUtils \
		p5-MaxMind-DB-Reader>=1:net/p5-MaxMind-DB-Reader \
		p5-Moo>=0:devel/p5-Moo \
		p5-Params-Validate>=0:devel/p5-Params-Validate \
		p5-Sub-Quote>=0:devel/p5-Sub-Quote \
		p5-Throwable>=0:devel/p5-Throwable \
		p5-Try-Tiny>=0:lang/p5-Try-Tiny \
		p5-URI>=0:net/p5-URI \
		p5-libwww>=0:www/p5-libwww \
		p5-namespace-clean>=0:devel/p5-namespace-clean
TEST_DEPENDS=	p5-MaxMind-DB-Common>=0:net/p5-MaxMind-DB-Common \
		p5-Path-Class>=0:devel/p5-Path-Class \
		p5-Test-Fatal>=0:devel/p5-Test-Fatal \
		p5-Test-Number-Delta>=0:devel/p5-Test-Number-Delta

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
