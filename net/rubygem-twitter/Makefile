# Created by: ijliao
# $FreeBSD$

PORTNAME=	twitter
PORTVERSION=	5.14.0
CATEGORIES=	net rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Ruby interface to the Twitter API

LICENSE=	MIT

RUN_DEPENDS=	rubygem-addressable>=2.3:${PORTSDIR}/www/rubygem-addressable \
		rubygem-buftok>=0.2.0:${PORTSDIR}/devel/rubygem-buftok \
		rubygem-equalizer>=0.0.9:${PORTSDIR}/devel/rubygem-equalizer \
		rubygem-faraday>=0.9.0:${PORTSDIR}/www/rubygem-faraday \
		rubygem-http>=0.6.0:${PORTSDIR}/www/rubygem-http \
		rubygem-http_parser.rb>=0.6.0:${PORTSDIR}/net/rubygem-http_parser.rb \
		rubygem-json>=1.8:${PORTSDIR}/devel/rubygem-json \
		rubygem-memoizable>=0.4.0:${PORTSDIR}/devel/rubygem-memoizable \
		rubygem-naught>=1.0:${PORTSDIR}/devel/rubygem-naught \
		rubygem-simple_oauth>=0.3.0:${PORTSDIR}/net/rubygem-simple_oauth

NO_ARCH=	yes

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
