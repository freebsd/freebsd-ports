# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Text-Table-Manifold
PORTVERSION=	1.00
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Render tables in manifold formats

LICENSE=	ART20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	p5-Const-Exporter>=0.2.3:devel/p5-Const-Exporter \
		p5-HTML-Entities-Interpolate>=1.05:textproc/p5-HTML-Entities-Interpolate \
		p5-List-AllUtils>=0.08:devel/p5-List-AllUtils \
		p5-Module-Runtime>=0.014:devel/p5-Module-Runtime \
		p5-Moo>=1.006000:devel/p5-Moo \
		p5-Type-Tiny>=1.000004:devel/p5-Type-Tiny \
		p5-Unicode-LineBreak>=2013.10:textproc/p5-Unicode-LineBreak
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_PERL5=	configure
USES=		perl5 tar:tgz

.include <bsd.port.mk>
