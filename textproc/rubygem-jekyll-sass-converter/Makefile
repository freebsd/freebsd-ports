PORTNAME=	jekyll-sass-converter
PORTVERSION=	2.2.0
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Basic Sass converter for Jekyll
WWW=		https://github.com/jekyll/jekyll-sass-converter

LICENSE=	MIT

RUN_DEPENDS=	rubygem-sassc>=2.1.0<3.0:textproc/rubygem-sassc

USES=		gem

NO_ARCH=	yes

# jekyll-sass-converter 3.0.0+ requires Dart Sass implementation
PORTSCOUT=	limit:^2\.

.include <bsd.port.mk>
