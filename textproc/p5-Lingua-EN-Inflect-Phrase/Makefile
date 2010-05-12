# New ports collection makefile for:	Lingua::EN::Inflect::Phrase
# Date created:		12 May 2010
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Lingua-EN-Inflect-Phrase
PORTVERSION=	0.04
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension to inflect short English Phrases

RUN_DEPENDS=	\
	p5-Lingua-EN-Inflect>=1.89.1:${PORTSDIR}/textproc/p5-Lingua-EN-Inflect \
	p5-Lingua-EN-Inflect-Number>=1.1:${PORTSDIR}/textproc/p5-Lingua-EN-Inflect-Number \
	p5-Lingua-EN-Tagger>=0.15:${PORTSDIR}/textproc/p5-Lingua-EN-Tagger
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Lingua::EN::Inflect::Phrase.3

.include <bsd.port.mk>
