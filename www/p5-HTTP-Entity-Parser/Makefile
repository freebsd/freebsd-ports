# $FreeBSD$

PORTNAME=	HTTP-Entity-Parser
PORTVERSION=	0.22
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	wen@FreeBSD.org
COMMENT=	PSGI compliant HTTP Entity Parser

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-JSON-MaybeXS>=0:converters/p5-JSON-MaybeXS \
		p5-WWW-Form-UrlEncoded>=0.23:www/p5-WWW-Form-UrlEncoded \
		p5-HTTP-MultiPartParser>=0:www/p5-HTTP-MultiPartParser \
		p5-Hash-MultiValue>=0:devel/p5-Hash-MultiValue \
		p5-Stream-Buffered>=0:devel/p5-Stream-Buffered

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	modbuildtiny

.include <bsd.port.mk>
