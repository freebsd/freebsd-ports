# Created by: Steve Wills <steve@mouf.net>
# $FreeBSD$

PORTNAME=	CGI-Application-Plugin-JSON
PORTVERSION=	1.02
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Easy manipulation of JSON headers for CGI::Application

BUILD_DEPENDS=	p5-CGI-Application>4.01:www/p5-CGI-Application \
		p5-JSON>=0:converters/p5-JSON \
		p5-JSON-Any>=0:converters/p5-JSON-Any
RUN_DEPENDS=	p5-CGI-Application>4.01:www/p5-CGI-Application \
		p5-JSON>=0:converters/p5-JSON \
		p5-JSON-Any>=0:converters/p5-JSON-Any

USES=		perl5
USE_PERL5=	modbuild

.include <bsd.port.mk>
