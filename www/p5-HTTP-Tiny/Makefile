# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	HTTP-Tiny
PORTVERSION=	0.049
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:DAGOLDEN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Small, simple, correct HTTP/1.1 client

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

OPTIONS_DEFINE=	COOKIE HTTPS IO_SOCKET_IP
OPTIONS_DEFAULT=COOKIE HTTPS IO_SOCKET_IP
IO_SOCKET_IP_DESC=	Use IO::Socket:IP instead of IO::Socket::INET

PORTSCOUT=	limit:^[0-9\.]*$$

USE_PERL5=	configure
USES=		perl5

COOKIE_BUILD_DEPENDS=	p5-HTTP-CookieJar>=0.001:${PORTSDIR}/www/p5-HTTP-CookieJar
COOKIE_RUN_DEPENDS=	p5-HTTP-CookieJar>=0.001:${PORTSDIR}/www/p5-HTTP-CookieJar
HTTPS_BUILD_DEPENDS=	p5-IO-Socket-SSL>=1.42:${PORTSDIR}/security/p5-IO-Socket-SSL \
			p5-Mozilla-CA>=20130114:${PORTSDIR}/www/p5-Mozilla-CA \
			p5-Net-SSLeay>=1.49:${PORTSDIR}/security/p5-Net-SSLeay
HTTPS_RUN_DEPENDS=	p5-IO-Socket-SSL>=1.42:${PORTSDIR}/security/p5-IO-Socket-SSL \
			p5-Mozilla-CA>=20130114:${PORTSDIR}/www/p5-Mozilla-CA \
			p5-Net-SSLeay>=1.49:${PORTSDIR}/security/p5-Net-SSLeay
IO_SOCKET_IP_BUILD_DEPENDS=	p5-IO-Socket-IP>=0.25:${PORTSDIR}/net/p5-IO-Socket-IP
IO_SOCKET_IP_RUN_DEPENDS=	p5-IO-Socket-IP>=0.25:${PORTSDIR}/net/p5-IO-Socket-IP

.include <bsd.port.mk>
