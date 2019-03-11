# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	GIS-Distance
PORTVERSION=	0.14
PORTEPOCH=	1
CATEGORIES=	math perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:BLUEFEET
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Calculate geographic distances

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Class-Measure>=0:devel/p5-Class-Measure \
		p5-Const-Fast>=0.014:devel/p5-Const-Fast \
		p5-GIS-Distance-Fast>=0.09:math/p5-GIS-Distance-Fast \
		p5-namespace-clean>=0.24:devel/p5-namespace-clean \
		p5-strictures>=2.000000:devel/p5-strictures
TEST_DEPENDS=	p5-Test2-Suite>=0.000094:devel/p5-Test2-Suite

USES=		perl5
USE_PERL5=	modbuildtiny

NO_ARCH=	yes

.include <bsd.port.mk>
