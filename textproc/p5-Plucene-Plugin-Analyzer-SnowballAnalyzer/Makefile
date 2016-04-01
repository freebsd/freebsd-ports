# Created by: Anton Berezin <tobez@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Plucene-Plugin-Analyzer-SnowballAnalyzer
PORTVERSION=	1.1
PORTREVISION=	2
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:FABPOT
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	Stemmed analyzer plugin for p5-Plucene search engine

BUILD_DEPENDS=	p5-Lingua-StopWords>=0:textproc/p5-Lingua-StopWords \
		p5-Lingua-Stem-Snowball>=0:textproc/p5-Lingua-Stem-Snowball \
		p5-Plucene>=0:textproc/p5-Plucene
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
