# Created by: Masahiro Teramoto <markun@onohara.to>
# $FreeBSD$

PORTNAME=	Text-Language-Guess
PORTVERSION=	0.02
PORTREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:MSCHILLI
PKGNAMEPREFIX=	p5-

MAINTAINER=	markun@onohara.to
COMMENT=	Trained module to guess a document's language

BUILD_DEPENDS=	p5-Log-Log4perl>=1.0:devel/p5-Log-Log4perl \
		p5-Text-ExtractWords>=0:textproc/p5-Text-ExtractWords \
		p5-Lingua-StopWords>=0:textproc/p5-Lingua-StopWords
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
