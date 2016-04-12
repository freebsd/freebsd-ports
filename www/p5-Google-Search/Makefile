# Created by: Emanuel Haupt <ehaupt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Google-Search
PORTVERSION=	0.028
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Interface to the Google AJAX Search API and suggestion API

RUN_DEPENDS=	p5-Any-Moose>=0:devel/p5-Any-Moose \
		p5-JSON>=2.16:converters/p5-JSON \
		p5-Carp-Clan-Share>=0:devel/p5-Carp-Clan-Share \
		p5-Test-Most>=0:devel/p5-Test-Most \
		p5-URI>=0:net/p5-URI \
		p5-libwww>0:www/p5-libwww \
		p5-Try-Tiny>=0.07:lang/p5-Try-Tiny
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
