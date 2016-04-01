# Created by: Anton Berezin <tobez@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Plucene
PORTVERSION=	1.25
PORTREVISION=	3
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:TMTM
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	Perl port of the Java Lucene search engine

BUILD_DEPENDS=	p5-Tie-Array-Sorted>=0:devel/p5-Tie-Array-Sorted \
		p5-File-Slurp>=0:devel/p5-File-Slurp \
		p5-Class-Virtual>=0:devel/p5-Class-Virtual \
		p5-Class-Accessor>=0:devel/p5-Class-Accessor \
		p5-Time-Piece>=0:devel/p5-Time-Piece \
		p5-Lingua-Stem>=0:textproc/p5-Lingua-Stem \
		p5-Bit-Vector-Minimal>=0:math/p5-Bit-Vector-Minimal \
		p5-IO-stringy>=0:devel/p5-IO-stringy
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
