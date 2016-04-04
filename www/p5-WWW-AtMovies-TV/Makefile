# Created by: chinsan
# $FreeBSD$

PORTNAME=	WWW-AtMovies-TV
PORTVERSION=	0.04
PORTREVISION=	1
DISTVERSIONPREFIX=v
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:ALEC
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Retrieve TV information from http://www.atmovies.com.tw/

BUILD_DEPENDS=	p5-HTML-TableExtract>=2.1:www/p5-HTML-TableExtract \
		p5-Moose>=0.55:devel/p5-Moose \
		p5-WWW-Mechanize>=1.34:www/p5-WWW-Mechanize
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
