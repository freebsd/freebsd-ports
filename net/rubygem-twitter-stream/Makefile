# Created by: TAKATSU Tomonari <tota@FreeBSD.org>
# $FreeBSD$

PORTNAME=	twitter-stream
PORTVERSION=	0.1.16
PORTREVISION=	1
CATEGORIES=	net rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Twitter realtime API client

LICENSE=	MIT

RUN_DEPENDS=	rubygem-eventmachine>=0.12.8:${PORTSDIR}/devel/rubygem-eventmachine \
		rubygem-http_parser.rb>=0.5.1:${PORTSDIR}/net/rubygem-http_parser.rb \
		rubygem-simple_oauth>=0.1.4:${PORTSDIR}/net/rubygem-simple_oauth

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
