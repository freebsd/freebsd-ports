# Created by: Anton Berezin <tobez@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Lingua-Identify
PORTVERSION=	0.56
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	Lingua::Identify - Language identification
TAGS=		lang detect identify

BUILD_DEPENDS=	p5-Class-Factory-Util>=1.6:${PORTSDIR}/devel/p5-Class-Factory-Util \
		p5-Text-Affixes>=0.04:${PORTSDIR}/textproc/p5-Text-Affixes \
		p5-Text-Ngram>=0.03:${PORTSDIR}/textproc/p5-Text-Ngram
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN1=	langident.1 make-lingua-identify-language.1
MAN3=	Lingua::Identify.3 \
	Lingua::Identify::BG.3 \
	Lingua::Identify::CS.3 \
	Lingua::Identify::CY.3 \
	Lingua::Identify::DA.3 \
	Lingua::Identify::DE.3 \
	Lingua::Identify::EL.3 \
	Lingua::Identify::EN.3 \
	Lingua::Identify::ES.3 \
	Lingua::Identify::FI.3 \
	Lingua::Identify::FR.3 \
	Lingua::Identify::HR.3 \
	Lingua::Identify::HI.3 \
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
	Lingua::Identify::TR.3 \
	Lingua::Identify::UK.3

NO_STAGE=	yes
.include <bsd.port.mk>
