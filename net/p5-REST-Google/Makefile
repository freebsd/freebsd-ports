# Created by: Cheng-Lung Sung <clsung@FreeBSD.org>
# $FreeBSD$

PORTNAME=	REST-Google
PORTVERSION=	1.0.8
PORTREVISION=	2
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:EJS
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Access Google REST (aka AJAX) API from Perl

RUN_DEPENDS=	p5-libwww>=0:www/p5-libwww \
		p5-Class-Accessor>0:devel/p5-Class-Accessor \
		p5-Class-Data-Inheritable>0:devel/p5-Class-Data-Inheritable \
		p5-URI>=1.35:net/p5-URI \
		p5-JSON-Any>=1.16:converters/p5-JSON-Any
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	modbuild

.include <bsd.port.mk>
