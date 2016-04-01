# Created by: Steven Kreuzer <skreuzer@exit2shell.com>
# $FreeBSD$

PORTNAME=	Net-GeoPlanet
PORTVERSION=	0.2
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	skreuzer@FreeBSD.org
COMMENT=	Access Yahoo's GeoPlanet location service

RUN_DEPENDS=	p5-libwww>=5.805:www/p5-libwww \
		p5-URI>=1.35:net/p5-URI \
		p5-Test-Simple>=0.74:devel/p5-Test-Simple
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
