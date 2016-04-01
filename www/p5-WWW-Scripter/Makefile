# Created by: Emanuel Haupt <ehaupt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	WWW-Scripter
PORTVERSION=	0.031
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Module for scripting web sites that have scripts

RUN_DEPENDS=	p5-libwww>=5.829:www/p5-libwww \
		p5-WWW-Mechanize>=0:www/p5-WWW-Mechanize \
		p5-HTML-DOM>=0:www/p5-HTML-DOM \
		p5-CSS-DOM>=0:www/p5-CSS-DOM
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
