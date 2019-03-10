# Created by: Anton Berezin <tobez@FreeBSD.org>
# $FreeBSD$

PORTNAME=	GIS-Distance-Fast
PORTVERSION=	0.12
CATEGORIES=	math perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:BLUEFEET
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	C implementation of GIS::Distance formulas

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-namespace-clean>=0.24:devel/p5-namespace-clean \
		p5-strictures>=2.000000:devel/p5-strictures
TEST_DEPENDS=	p5-Test2-Suite>=0.000094:devel/p5-Test2-Suite

USES=		perl5
USE_PERL5=	modbuildtiny

.include <bsd.port.mk>
