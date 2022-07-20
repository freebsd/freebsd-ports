PORTNAME=	Data-Entropy
PORTVERSION=	0.007
PORTREVISION=	1
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Entropy (randomness) management

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

RUN_DEPENDS=	p5-Crypt-Rijndael>=0:security/p5-Crypt-Rijndael \
		p5-Data-Float>=0.008:math/p5-Data-Float \
		p5-HTTP-Lite>=0.22:www/p5-HTTP-Lite \
		p5-Params-Classify>=0:devel/p5-Params-Classify

USES=		perl5
USE_PERL5=	modbuild
NO_ARCH=	yes

.include <bsd.port.mk>
