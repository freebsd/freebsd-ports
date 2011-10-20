# New ports collection makefile for:	p5-Geo-Coder-Many
# Date created:		2011-10-13
# Whom:			Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Geo-Coder-Many
PORTVERSION=	0.28
CATEGORIES=	misc geography perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Module to tie together multiple Geo::Coder::* modules

BUILD_DEPENDS=	p5-Geo-Coder-Bing>=0.10:${PORTSDIR}/misc/p5-Geo-Coder-Bing \
		p5-Geo-Coder-Google>=0.06:${PORTSDIR}/misc/p5-Geo-Coder-Google \
		p5-Geo-Coder-Googlev3>=0.07:${PORTSDIR}/misc/p5-Geo-Coder-Googlev3 \
		p5-Geo-Coder-Mapquest>=0.04:${PORTSDIR}/misc/p5-Geo-Coder-Mapquest \
		p5-Geo-Coder-Multimap>=0.01:${PORTSDIR}/misc/p5-Geo-Coder-Multimap \
		p5-Geo-Coder-OSM>=0.01:${PORTSDIR}/misc/p5-Geo-Coder-OSM \
		p5-Geo-Coder-Ovi>=0.01:${PORTSDIR}/misc/p5-Geo-Coder-Ovi \
		p5-Geo-Coder-PlaceFinder>=0.02:${PORTSDIR}/misc/p5-Geo-Coder-PlaceFinder \
		p5-Geo-Distance-XS>=0.08:${PORTSDIR}/math/p5-Geo-Distance-XS \
		p5-HTTP-Message>=5.827:${PORTSDIR}/www/p5-HTTP-Message \
		p5-List-MoreUtils>=0.22:${PORTSDIR}/lang/p5-List-MoreUtils \
		p5-List-Util-WeightedRoundRobin>=0.4:${PORTSDIR}/misc/p5-List-Util-WeightedRoundRobin
RUN_DEPENDS:=	${BUILD_DEPENDS}

TEST_DEPENDS=	p5-Test-Exception>=0:${PORTSDIR}/devel/p5-Test-Exception \
		p5-Test-MockObject>=0:${PORTSDIR}/devel/p5-Test-MockObject \
		p5-Test-Pod-Coverage>=0:${PORTSDIR}/devel/p5-Test-Pod-Coverage

PERL_CONFIGURE=	5.10.0+

MAN3=		Geo::Coder::Many.3 \
		Geo::Coder::Many::Bing.3 \
		Geo::Coder::Many::Generic.3 \
		Geo::Coder::Many::Google.3 \
		Geo::Coder::Many::Googlev3.3 \
		Geo::Coder::Many::Mapquest.3 \
		Geo::Coder::Many::OSM.3 \
		Geo::Coder::Many::Ovi.3 \
		Geo::Coder::Many::PlaceFinder.3 \
		Geo::Coder::Many::Response.3 \
		Geo::Coder::Many::Scheduler.3 \
		Geo::Coder::Many::Scheduler::OrderedList.3 \
		Geo::Coder::Many::Scheduler::Selective.3 \
		Geo::Coder::Many::Scheduler::UniquenessScheduler.3 \
		Geo::Coder::Many::Scheduler::UniquenessScheduler::WRR.3 \
		Geo::Coder::Many::Scheduler::UniquenessScheduler::WeightedRandom.3 \
		Geo::Coder::Many::Util.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501400
BUILD_DEPENDS+=	p5-Scalar-List-Utils>=1.23:${PORTSDIR}/lang/p5-Scalar-List-Utils
RUN_DEPENDS+=	p5-Scalar-List-Utils>=1.23:${PORTSDIR}/lang/p5-Scalar-List-Utils
.endif

.include <bsd.port.post.mk>
