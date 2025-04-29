PORTNAME=	Data-Entropy
PORTVERSION=	0.008
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Entropy (randomness) management
WWW=		https://metacpan.org/release/Data-Entropy

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

DEPRECATED=	The maintainer of this distribution has indicated that it is deprecated and no longer suitable for use
EXPIRATION_DATE=2025-05-31

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Crypt-Rijndael>=0:security/p5-Crypt-Rijndael \
		p5-Crypt-URandom>=0.36:security/p5-Crypt-URandom \
		p5-Data-Float>=0.008:math/p5-Data-Float \
		p5-HTTP-Lite>=2.20:www/p5-HTTP-Lite \
		p5-Module-Build>=0:devel/p5-Module-Build \
		p5-Params-Classify>=0:devel/p5-Params-Classify

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
