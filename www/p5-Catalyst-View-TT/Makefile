# Created by: Lars Thegler <lth@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Catalyst-View-TT
PORTVERSION=	0.44
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Template Toolkit view class for Catalyst

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Catalyst-Runtime>=5.7000:www/p5-Catalyst-Runtime \
		p5-Class-Accessor>=0:devel/p5-Class-Accessor \
		p5-Data-Dump>=0:devel/p5-Data-Dump \
		p5-MRO-Compat>=0:devel/p5-MRO-Compat \
		p5-Path-Class>=0:devel/p5-Path-Class \
		p5-Template-Timer>=0:www/p5-Template-Timer \
		p5-Template-Toolkit>=0:www/p5-Template-Toolkit
RUN_DEPENDS:=	${BUILD_DEPENDS}

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
