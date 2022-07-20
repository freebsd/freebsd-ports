PORTNAME=	WWW-OAuth
PORTVERSION=	1.000
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Portable OAuth 1.0 authentication

LICENSE=	ART20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Class-Tiny-Chained>0:devel/p5-Class-Tiny-Chained \
		p5-HTTP-Message>0:www/p5-HTTP-Message \
		p5-Module-Runtime>0:devel/p5-Module-Runtime \
		p5-Mojolicious>0:www/p5-Mojolicious \
		p5-Role-Tiny>0:devel/p5-Role-Tiny \
		p5-URI>0:net/p5-URI \
		p5-WWW-Form-UrlEncoded>0:www/p5-WWW-Form-UrlEncoded \
		p5-libwww>0:www/p5-libwww

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
