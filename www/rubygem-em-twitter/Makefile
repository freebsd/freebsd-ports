# Created by: TAKATSU Tomonari <tota@FreeBSD.org>
# $FreeBSD$

PORTNAME=	em-twitter
PORTVERSION=	0.3.2
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Twitter Streaming API client for EventMachine

LICENSE=	MIT

RUN_DEPENDS=	rubygem-eventmachine>=1:${PORTSDIR}/devel/rubygem-eventmachine \
		rubygem-http_parser.rb>=0.6:${PORTSDIR}/net/rubygem-http_parser.rb \
		rubygem-simple_oauth>=0.2:${PORTSDIR}/net/rubygem-simple_oauth

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
