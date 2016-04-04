# Created by: Lars Thegler <lth@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Feed-Find
PORTVERSION=	0.07
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:BTROTT
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Syndication feed auto-discovery

RUN_DEPENDS=	p5-URI>=0:net/p5-URI \
		p5-HTML-Parser>=0:www/p5-HTML-Parser \
		p5-libwww>=0:www/p5-libwww \
		p5-Class-ErrorHandler>=0:devel/p5-Class-ErrorHandler
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
