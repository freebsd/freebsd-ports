# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	GeoIP2
PORTVERSION=	2.003005
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:MAXMIND
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Perl API for MaxMind GeoIP2 web services and databases

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	p5-Data-Validate-IP>=0.19:net-mgmt/p5-Data-Validate-IP \
		p5-HTTP-Message>=0:www/p5-HTTP-Message \
		p5-JSON-MaybeXS>=0:converters/p5-JSON-MaybeXS \
		p5-LWP-Protocol-https>=0:www/p5-LWP-Protocol-https \
		p5-List-MoreUtils>=0:lang/p5-List-MoreUtils \
		p5-MaxMind-DB-Common>=0:net/p5-MaxMind-DB-Common \
		p5-MaxMind-DB-Reader>=0:net/p5-MaxMind-DB-Reader \
		p5-Moo>=0:devel/p5-Moo \
		p5-Params-Validate>=0:devel/p5-Params-Validate \
		p5-Throwable>=0:devel/p5-Throwable \
		p5-Try-Tiny>=0:lang/p5-Try-Tiny \
		p5-URI>=0:net/p5-URI \
		p5-libwww>=0:www/p5-libwww \
		p5-namespace-clean>=0:devel/p5-namespace-clean
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-HTTP-Message>=0:www/p5-HTTP-Message \
		p5-Path-Class>=0:devel/p5-Path-Class \
		p5-Test-Fatal>=0:devel/p5-Test-Fatal \
		p5-Test-Number-Delta>=0:devel/p5-Test-Number-Delta

NO_ARCH=	yes
USE_PERL5=	configure
USES=		perl5

.include <bsd.port.mk>
