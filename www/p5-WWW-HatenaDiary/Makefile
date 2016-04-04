# Created by: Masahiro Teramoto <markun@onohara.to>
# $FreeBSD$

PORTNAME=	WWW-HatenaDiary
PORTVERSION=	0.02
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	markun@onohara.to
COMMENT=	CRUD interface to Hatena::Diary

BUILD_DEPENDS=	p5-YAML-Syck>=0:textproc/p5-YAML-Syck \
		p5-URI>=0:net/p5-URI \
		p5-WWW-HatenaLogin>=0.02:www/p5-WWW-HatenaLogin \
		p5-WWW-Mechanize>=0:www/p5-WWW-Mechanize \
		p5-Web-Scraper>=0:www/p5-Web-Scraper
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
