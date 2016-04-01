# Created by: Espen Tagestad <espen@tagestad.no>
# $FreeBSD$

PORTNAME=	CGI-Application-Plugin-HTDot
PORTVERSION=	0.07
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	culot@FreeBSD.org
COMMENT=	Enable "magic dot" notation in CGI::Application-derived applications

BUILD_DEPENDS=	p5-CGI-Application>=4.0:www/p5-CGI-Application \
		p5-Test-Exception>=0:devel/p5-Test-Exception \
		p5-HTML-Template-Pluggable>=0:www/p5-HTML-Template-Pluggable \
		p5-CGI-Application>=0:www/p5-CGI-Application \
		p5-Test-Simple>=0:devel/p5-Test-Simple
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
