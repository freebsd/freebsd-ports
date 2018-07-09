# $FreeBSD$

PORTNAME=	Geo-Coder-Multiple
PORTVERSION=	0.60
PORTREVISION=	1
CATEGORIES=	misc perl5 geography
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-0.6

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Perl module to tie together multiple Geo::Coder modules

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-List-Util-WeightedRoundRobin>=0:misc/p5-List-Util-WeightedRoundRobin

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
