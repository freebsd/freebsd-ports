# New ports collection makefile for:	textproc/p5-Lingua-Identify
# Date created:				11 November 2005
# Whom:					Anton Berezin <tobez@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Lingua-Identify
PORTVERSION=	0.31
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	Lingua::Identify - Language identification
TAGS=		lang detect identify

COMMON_DEPENDS=	p5-Class-Factory-Util>=1.6:${PORTSDIR}/devel/p5-Class-Factory-Util \
		p5-Text-Affixes>=0.04:${PORTSDIR}/textproc/p5-Text-Affixes \
		p5-Text-Ngram>=0.03:${PORTSDIR}/textproc/p5-Text-Ngram
BUILD_DEPENDS=	${COMMON_DEPENDS}
RUN_DEPENDS=	${COMMON_DEPENDS}

PERL_CONFIGURE=	yes

MAN1=	langident.1 make-lingua-identify-language.1
MAN3=	Lingua::Identify.3 \
	Lingua::Identify::BG.3 \
	Lingua::Identify::DA.3 \
	Lingua::Identify::DE.3 \
	Lingua::Identify::EL.3 \
	Lingua::Identify::EN.3 \
	Lingua::Identify::ES.3 \
	Lingua::Identify::FI.3 \
	Lingua::Identify::FR.3 \
	Lingua::Identify::HR.3 \
	Lingua::Identify::HU.3 \
	Lingua::Identify::ID.3 \
	Lingua::Identify::IT.3 \
	Lingua::Identify::LA.3 \
	Lingua::Identify::NL.3 \
	Lingua::Identify::Nothing.3 \
	Lingua::Identify::PL.3 \
	Lingua::Identify::PT.3 \
	Lingua::Identify::RO.3 \
	Lingua::Identify::RU.3 \
	Lingua::Identify::SL.3 \
	Lingua::Identify::SQ.3 \
	Lingua::Identify::SV.3 \
	Lingua::Identify::TR.3

.include <bsd.port.mk>
