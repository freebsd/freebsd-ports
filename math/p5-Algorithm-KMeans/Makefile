# New ports collection makefile for:	p5-Algorithm-KMeans
# Date created:				30 June, 2010
# Whom:					Wen Heping <wen@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Algorithm-KMeans
PORTVERSION=	1.21
CATEGORIES=	math perl5
MASTER_SITES=	CPAN/../../authors/id/A/AV/AVIKAK/
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Clustering multi-dimensional data with a pure-Perl implementation

RUN_DEPENDS=	p5-Math-Random>=0.71:${PORTSDIR}/math/p5-Math-Random \
		p5-Graphics-GnuplotIF>1.4:${PORTSDIR}/graphics/p5-Graphics-GnuplotIF

MAN3=		Algorithm::KMeans.3

PERL_CONFIGURE=	yes

.include <bsd.port.mk>
