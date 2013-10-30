# Created by: TAKATSU Tomonari <tota@FreeBSD.org>
# $FreeBSD$

PORTNAME=	em-twitter
PORTVERSION=	0.2.2
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Twitter Streaming API client for EventMachine

RUN_DEPENDS=	rubygem-eventmachine>=1.0.0:${PORTSDIR}/devel/rubygem-eventmachine \
		rubygem-http_parser.rb>=0.5:${PORTSDIR}/net/rubygem-http_parser.rb \
		rubygem-simple_oauth>=0.1:${PORTSDIR}/net/rubygem-simple_oauth

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
