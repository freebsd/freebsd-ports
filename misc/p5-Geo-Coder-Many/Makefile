# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Geo-Coder-Many
PORTVERSION=	0.46
DISTVERSIONSUFFIX=	-5
PORTREVISION=	1
CATEGORIES=	misc geography perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Module to tie together multiple Geo::Coder::* modules

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Geo-Coder-Bing>=0.10:misc/p5-Geo-Coder-Bing \
		p5-Geo-Coder-Google>=0.06:misc/p5-Geo-Coder-Google \
		p5-Geo-Coder-Googlev3>=0.07:misc/p5-Geo-Coder-Googlev3 \
		p5-Geo-Coder-Mapquest>=0.05:misc/p5-Geo-Coder-Mapquest \
		p5-Geo-Coder-Multimap>=0.01:misc/p5-Geo-Coder-Multimap \
		p5-Geo-Coder-OSM>=0.01:misc/p5-Geo-Coder-OSM \
		p5-Geo-Coder-OpenCage>=0:misc/p5-Geo-Coder-OpenCage \
		p5-Geo-Coder-Ovi>=0.01:misc/p5-Geo-Coder-Ovi \
		p5-Geo-Coder-PlaceFinder>=0.02:misc/p5-Geo-Coder-PlaceFinder \
		p5-Geo-Distance-XS>=0.08:math/p5-Geo-Distance-XS \
		p5-HTTP-Message>=5.827:www/p5-HTTP-Message \
		p5-List-MoreUtils>=0.22:lang/p5-List-MoreUtils \
		p5-List-Util-WeightedRoundRobin>=0.4:misc/p5-List-Util-WeightedRoundRobin \
		p5-Sort-Versions>=1.5:devel/p5-Sort-Versions
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Exception>=0:devel/p5-Test-Exception \
		p5-Test-MockObject>=0:devel/p5-Test-MockObject \
		p5-Test-Pod-Coverage>=0:devel/p5-Test-Pod-Coverage

NO_ARCH=	yes
USE_PERL5=	configure
USES=		perl5
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

.include <bsd.port.mk>
