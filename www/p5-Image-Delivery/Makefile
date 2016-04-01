# Created by: TAKAHASHI Kaoru <kaoru@kaisei.org>
# $FreeBSD$

PORTNAME=	Image-Delivery
PORTVERSION=	0.14
PORTREVISION=	2
CATEGORIES=	www graphics perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	coryking@mozimedia.com
COMMENT=	Efficient transformation and delivery of web images

BUILD_DEPENDS=	p5-Test-ClassAPI>=1.04:devel/p5-Test-ClassAPI \
		p5-Digest-TransformPath>=0.01:devel/p5-Digest-TransformPath \
		p5-File-Remove>=0.34:devel/p5-File-Remove \
		p5-File-Slurp>=9999.04:devel/p5-File-Slurp \
		p5-HTML-Location>=1.00:www/p5-HTML-Location \
		p5-Params-Coerce>=0.13:devel/p5-Params-Coerce
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
