# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	HTTP-Tiny
PORTVERSION=	0.058
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Small, simple, correct HTTP/1.1 client

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

OPTIONS_DEFINE=	COOKIE HTTPS IO_SOCKET_IP
OPTIONS_DEFAULT=COOKIE HTTPS IO_SOCKET_IP
IO_SOCKET_IP_DESC=	Use IO::Socket:IP instead of IO::Socket::INET

PORTSCOUT=	limit:^[0-9\.]*$$

NO_ARCH=	yes
USE_PERL5=	configure
USES=		perl5

COOKIE_BUILD_DEPENDS=	p5-HTTP-CookieJar>=0.001:www/p5-HTTP-CookieJar
COOKIE_RUN_DEPENDS=	p5-HTTP-CookieJar>=0.001:www/p5-HTTP-CookieJar
HTTPS_BUILD_DEPENDS=	p5-IO-Socket-SSL>=1.42:security/p5-IO-Socket-SSL \
			p5-Mozilla-CA>=20160104:www/p5-Mozilla-CA \
			p5-Net-SSLeay>=1.49:security/p5-Net-SSLeay
HTTPS_RUN_DEPENDS=	p5-IO-Socket-SSL>=1.42:security/p5-IO-Socket-SSL \
			p5-Mozilla-CA>=20160104:www/p5-Mozilla-CA \
			p5-Net-SSLeay>=1.49:security/p5-Net-SSLeay

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 502200 && ${PORT_OPTIONS:MIO_SOCKET_IP}
BUILD_DEPENDS+=	p5-IO-Socket-IP>=0.32:net/p5-IO-Socket-IP
RUN_DEPENDS+=	p5-IO-Socket-IP>=0.32:net/p5-IO-Socket-IP
.endif

.include <bsd.port.post.mk>
