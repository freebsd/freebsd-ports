# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	Plucene-Analysis-CJKAnalyzer
PORTVERSION=	0.02
PORTREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:XERN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Analyzer for CJK texts

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Plucene>=0:textproc/p5-Plucene
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-YAML>=0:textproc/p5-YAML

USE_PERL5=	configure
USES=		perl5

.include <bsd.port.mk>
