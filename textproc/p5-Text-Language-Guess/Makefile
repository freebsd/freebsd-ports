# New ports collection makefile for:	textproc/p5-Text-Language-Guess
# Date created:		2006-09-25
# Whom:			Masahiro Teramoto <markun@onohara.to>
#
# $FreeBSD$
#

PORTNAME=	Text-Language-Guess
PORTVERSION=	0.02
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../../authors/id/M/MS/MSCHILLI
PKGNAMEPREFIX=	p5-

MAINTAINER=	markun@onohara.to
COMMENT=	Trained module to guess a document's language

BUILD_DEPENDS=	p5-Log-Log4perl>=1.0:${PORTSDIR}/devel/p5-Log-Log4perl \
		p5-Text-ExtractWords>=0:${PORTSDIR}/textproc/p5-Text-ExtractWords \
		p5-Lingua-StopWords>=0:${PORTSDIR}/textproc/p5-Lingua-StopWords
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN1=		language-guess.1
MAN3=		Text::Language::Guess.3

.include <bsd.port.mk>
