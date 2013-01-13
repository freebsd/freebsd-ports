# $FreeBSD$

PORTNAME=	Lingua-EN-Inflect-Phrase
PORTVERSION=	0.18
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension to inflect short English Phrases

RUN_DEPENDS=	\
	p5-Lingua-EN-FindNumber>=0:${PORTSDIR}/textproc/p5-Lingua-EN-FindNumber \
	p5-Lingua-EN-Inflect>=1.89.1:${PORTSDIR}/textproc/p5-Lingua-EN-Inflect \
	p5-Lingua-EN-Inflect-Number>=1.1:${PORTSDIR}/textproc/p5-Lingua-EN-Inflect-Number \
	p5-Lingua-EN-Number-IsOrdinal>0:${PORTSDIR}/textproc/p5-Lingua-EN-Number-IsOrdinal \
	p5-Lingua-EN-Tagger>=0.20:${PORTSDIR}/textproc/p5-Lingua-EN-Tagger
BUILD_DEPENDS:=	${RUN_DEPENDS}
TEST_DEPENDS=	\
	p5-Lingua-EN-Number-IsOrdinal>0:${PORTSDIR}/textproc/p5-Lingua-EN-Number-IsOrdinal \
	p5-Test-NoWarnings>=0:${PORTSDIR}/devel/p5-Test-NoWarnings

PERL_CONFIGURE=	yes

MAN3=	Lingua::EN::Inflect::Phrase.3

.include <bsd.port.mk>
