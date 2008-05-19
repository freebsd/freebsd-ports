# New ports collection makefile for:	p5-Plucene-Analysis-CJKAnalyzer
# Date created:		2007-07-07
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	Plucene-Analysis-CJKAnalyzer
PORTVERSION=	0.02
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/X/XE/XERN
PKGNAMEPREFIX=	p5-

MAINTAINER=	gslin@gslin.org
COMMENT=	Analyzer for CJK texts

RUN_DEPENDS=	${SITE_PERL}/Plucene.pm:${PORTSDIR}/textproc/p5-Plucene
BUILD_DEPENDS:=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Plucene::Analysis::CJKAnalyzer.3 \
		Plucene::Analysis::CJKTokenizer.3

.include <bsd.port.mk>
