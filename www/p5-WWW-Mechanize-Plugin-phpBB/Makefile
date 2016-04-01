# Created by: Aaron Dalton <aaron@FreeBSD.org>
# $FreeBSD$

PORTNAME=	WWW-Mechanize-Plugin-phpBB
PORTVERSION=	0.02
PORTREVISION=	2
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Screen scraper for phpBB installations

BUILD_DEPENDS=	p5-WWW-Mechanize>=0:www/p5-WWW-Mechanize \
		p5-WWW-Mechanize-Pluggable>=0.10:www/p5-WWW-Mechanize-Pluggable \
		p5-HTML-Tree>=0:www/p5-HTML-Tree \
		p5-Log-Log4perl>=1.0:devel/p5-Log-Log4perl \
		p5-Class-Accessor>=0.19:devel/p5-Class-Accessor
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
