# $FreeBSD$

PORTNAME=	Algorithm-KMeans
PORTVERSION=	2.05
PORTREVISION=	1
CATEGORIES=	math perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:AVIKAK
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Clustering multi-dimensional data with a pure-Perl implementation

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Graphics-GnuplotIF>=1.4:graphics/p5-Graphics-GnuplotIF \
		p5-Math-GSL>=0.26:math/p5-Math-GSL \
		p5-Math-Random>=0.71:math/p5-Math-Random

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
