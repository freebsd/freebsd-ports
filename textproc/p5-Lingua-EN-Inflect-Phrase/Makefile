PORTNAME=	Lingua-EN-Inflect-Phrase
PORTVERSION=	0.20
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl extension to inflect short English Phrases

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Lingua-EN-FindNumber>=0:textproc/p5-Lingua-EN-FindNumber \
		p5-Lingua-EN-Inflect>=0:textproc/p5-Lingua-EN-Inflect \
		p5-Lingua-EN-Inflect-Number>=0:textproc/p5-Lingua-EN-Inflect-Number \
		p5-Lingua-EN-Number-IsOrdinal>=0:textproc/p5-Lingua-EN-Number-IsOrdinal \
		p5-Lingua-EN-Tagger>=0.20:textproc/p5-Lingua-EN-Tagger
TEST_DEPENDS=	p5-Test-NoWarnings>=0:devel/p5-Test-NoWarnings

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
