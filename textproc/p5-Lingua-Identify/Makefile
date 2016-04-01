# Created by: Anton Berezin <tobez@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Lingua-Identify
PORTVERSION=	0.56
PORTREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	Lingua::Identify - Language identification

BUILD_DEPENDS=	p5-Class-Factory-Util>=1.6:devel/p5-Class-Factory-Util \
		p5-Text-Affixes>=0.04:textproc/p5-Text-Affixes \
		p5-Text-Ngram>=0.03:textproc/p5-Text-Ngram
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

TAGS=		lang detect identify

.include <bsd.port.mk>
