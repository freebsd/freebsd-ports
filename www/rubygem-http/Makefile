# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	http
PORTVERSION=	0.8.12
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Simple Ruby DSL for making HTTP requests

LICENSE=	MIT

RUN_DEPENDS=	rubygem-addressable>=2.3:${PORTSDIR}/www/rubygem-addressable \
		rubygem-http-cookie>=1.0:${PORTSDIR}/www/rubygem-http-cookie \
		rubygem-http-form_data>=1.0.1:${PORTSDIR}/www/rubygem-http-form_data \
		rubygem-http_parser.rb>=0.6.0:${PORTSDIR}/net/rubygem-http_parser.rb

NO_ARCH=	yes

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
