# Created by: Masahiro Teramoto <markun@onohara.to>
# $FreeBSD$

PORTNAME=	WWW-Mixi-Scraper
PORTVERSION=	0.34
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	markun@onohara.to
COMMENT=	Yet another mixi scraper

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

RUN_DEPENDS=	p5-Module-Find>=0:devel/p5-Module-Find \
		p5-String-CamelCase>=0:textproc/p5-String-CamelCase \
		p5-Test-UseAllModules>=0:devel/p5-Test-UseAllModules \
		p5-URI>=0:net/p5-URI \
		p5-Web-Scraper>=0.17:www/p5-Web-Scraper \
		p5-WWW-Mechanize>=1.50:www/p5-WWW-Mechanize
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5 dos2unix
USE_PERL5=	configure

.include <bsd.port.mk>
