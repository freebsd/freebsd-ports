PORTNAME=	Lingua-EN-Tagger
PORTVERSION=	0.31
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Part-of-speech tagger for English natural language processing

LICENSE=	GPLv3

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-HTML-Parser>=3.45:www/p5-HTML-Parser \
		p5-HTML-Tagset>=3.20:www/p5-HTML-Tagset \
		p5-Lingua-Stem>=0.81:textproc/p5-Lingua-Stem \
		p5-Memoize-ExpireLRU>=0.55:devel/p5-Memoize-ExpireLRU

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
