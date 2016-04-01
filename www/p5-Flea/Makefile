# $FreeBSD$

PORTNAME=	Flea
PORTVERSION=	0.04
PORTREVISION=	2
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:FRODWITH
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for minimalistic sugar for your Plack

RUN_DEPENDS=	\
	p5-Devel-Declare-Parser>0:devel/p5-Devel-Declare-Parser \
	p5-Exception-Class>0:devel/p5-Exception-Class \
	p5-Exporter-Declare>=0.100:devel/p5-Exporter-Declare \
	p5-HTTP-Exception>0:www/p5-HTTP-Exception \
	p5-JSON>0:converters/p5-JSON \
	p5-Plack>0:www/p5-Plack \
	p5-Try-Tiny>0:lang/p5-Try-Tiny \
	p5-URI>0:net/p5-URI
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
