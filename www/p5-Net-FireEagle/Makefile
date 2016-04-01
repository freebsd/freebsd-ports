# Created by: Steven Kreuzer <skreuzer@exit2shel.com>
# $FreeBSD$

PORTNAME=	Net-FireEagle
PORTVERSION=	1.6
PORTREVISION=	2
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	skreuzer@FreeBSD.org
COMMENT=	Access Yahoo's FireEagle location service

RUN_DEPENDS=	p5-Net-OAuth-Simple>=1.0:net/p5-Net-OAuth-Simple \
		p5-libwww>=5.805:www/p5-libwww \
		p5-JSON-Any>=1.15:converters/p5-JSON-Any \
		p5-Net-SSLeay>=1.30:security/p5-Net-SSLeay
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
