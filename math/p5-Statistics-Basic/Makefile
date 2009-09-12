# New ports collection makefile for:	math/p5-Statistics-Basic
# Date created:				28 July 2009
# Whom:					Anton Berezin <tobez@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Statistics-Basic
PORTVERSION=	1.6601
CATEGORIES=	math perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	Statistics
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	A collection of very basic statistics modules

BUILD_DEPENDS=	p5-Number-Format>=1.61:${PORTSDIR}/textproc/p5-Number-Format
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Statistics::Basic.3 \
	Statistics::Basic::ComputedVector.3 \
	Statistics::Basic::Correlation.3 \
	Statistics::Basic::Covariance.3 \
	Statistics::Basic::LeastSquareFit.3 \
	Statistics::Basic::Mean.3 \
	Statistics::Basic::Median.3 \
	Statistics::Basic::Mode.3 \
	Statistics::Basic::StdDev.3 \
	Statistics::Basic::Variance.3 \
	Statistics::Basic::Vector.3 \
	Statistics::Basic::_OneVectorBase.3 \
	Statistics::Basic::_TwoVectorBase.3

.include <bsd.port.mk>
