# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	GIS-Distance
PORTVERSION=	0.09
PORTEPOCH=	1
CATEGORIES=	math perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:BLUEFEET
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Calculate geographic distances

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Class-Measure>=0:devel/p5-Class-Measure \
		p5-Moo>=1.006000:devel/p5-Moo \
		p5-Type-Tiny>=1:devel/p5-Type-Tiny \
		p5-namespace-clean>=0:devel/p5-namespace-clean \
		p5-strictures>=1:devel/p5-strictures
RUN_DEPENDS:=	${BUILD_DEPENDS}

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
