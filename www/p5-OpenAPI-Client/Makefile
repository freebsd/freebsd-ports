PORTNAME=	OpenAPI-Client
PORTVERSION=	1.07
CATEGORIES=	www perl5
MASTER_SITES=	CPAN/Mojolicious
PKGNAMEPREFIX=	p5-

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Client for talking to an OpenAPI-powered server
WWW=		https://metacpan.org/pod/OpenAPI::Client

LICENSE=	ART20

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Mojolicious>=1:www/p5-Mojolicious \
		p5-JSON-Validator>=0:textproc/p5-JSON-Validator

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
