PORTNAME=	HTTP-Tiny
PORTVERSION=	0.088
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Small, simple, correct HTTP/1.1 client
WWW=		https://metacpan.org/release/HTTP-Tiny

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

PORTSCOUT=	limit:^[0-9\.]*$$

OPTIONS_DEFINE=	CERTS COOKIE HTTPS IO_SOCKET_IP
OPTIONS_DEFAULT=CERTS COOKIE HTTPS IO_SOCKET_IP
CERTS_DESC=		Install the Mozilla CA cert bundle
IO_SOCKET_IP_DESC=	Use IO::Socket:IP instead of IO::Socket::INET

CERTS_BUILD_DEPENDS=	p5-Mozilla-CA>=20160104:www/p5-Mozilla-CA
CERTS_RUN_DEPENDS=	p5-Mozilla-CA>=20160104:www/p5-Mozilla-CA
COOKIE_BUILD_DEPENDS=	p5-HTTP-CookieJar>=0.001:www/p5-HTTP-CookieJar
COOKIE_RUN_DEPENDS=	p5-HTTP-CookieJar>=0.001:www/p5-HTTP-CookieJar
HTTPS_BUILD_DEPENDS=	p5-IO-Socket-SSL>=1.42:security/p5-IO-Socket-SSL \
			p5-Net-SSLeay>=1.49:security/p5-Net-SSLeay
HTTPS_RUN_DEPENDS=	p5-IO-Socket-SSL>=1.42:security/p5-IO-Socket-SSL \
			p5-Net-SSLeay>=1.49:security/p5-Net-SSLeay

.include <bsd.port.mk>
