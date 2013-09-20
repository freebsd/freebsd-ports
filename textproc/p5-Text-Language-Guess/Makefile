# Created by: Masahiro Teramoto <markun@onohara.to>
# $FreeBSD$

PORTNAME=	Text-Language-Guess
PORTVERSION=	0.02
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:MSCHILLI
PKGNAMEPREFIX=	p5-

MAINTAINER=	markun@onohara.to
COMMENT=	Trained module to guess a document's language

BUILD_DEPENDS=	p5-Log-Log4perl>=1.0:${PORTSDIR}/devel/p5-Log-Log4perl \
		p5-Text-ExtractWords>=0:${PORTSDIR}/textproc/p5-Text-ExtractWords \
		p5-Lingua-StopWords>=0:${PORTSDIR}/textproc/p5-Lingua-StopWords
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN1=		language-guess.1
MAN3=		Text::Language::Guess.3

NO_STAGE=	yes
.include <bsd.port.mk>
