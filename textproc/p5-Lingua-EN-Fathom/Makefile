PORTNAME=	Lingua-EN-Fathom
PORTVERSION=	1.22
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Measure readability of English text

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Lingua-EN-Sentence>=0.28:textproc/p5-Lingua-EN-Sentence \
		p5-Lingua-EN-Syllable>=0:textproc/p5-Lingua-EN-Syllable

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
