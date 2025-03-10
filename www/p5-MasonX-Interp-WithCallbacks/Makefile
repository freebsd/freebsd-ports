PORTNAME=	MasonX-Interp-WithCallbacks
PORTVERSION=	1.20
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Mason callback support via Params::CallbackRequest
WWW=		https://metacpan.org/release/MasonX-Interp-WithCallbacks

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Class-Container>=0.09:devel/p5-Class-Container \
		p5-HTML-Mason>=1.23:www/p5-HTML-Mason \
		p5-Params-CallbackRequest>=1.15:devel/p5-Params-CallbackRequest

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

USES=		perl5
USE_PERL5=	modbuild

NO_ARCH=	yes

.include <bsd.port.mk>
