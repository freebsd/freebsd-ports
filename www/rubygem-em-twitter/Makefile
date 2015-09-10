# Created by: TAKATSU Tomonari <tota@FreeBSD.org>
# $FreeBSD$

PORTNAME=	em-twitter
PORTVERSION=	0.3.5
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Twitter Streaming API client for EventMachine

LICENSE=	MIT

RUN_DEPENDS=	rubygem-buftok>=0.2:${PORTSDIR}/devel/rubygem-buftok \
		rubygem-eventmachine>=1.0:${PORTSDIR}/devel/rubygem-eventmachine \
		rubygem-http_parser.rb>=0.6:${PORTSDIR}/net/rubygem-http_parser.rb \
		rubygem-simple_oauth>=0.2:${PORTSDIR}/net/rubygem-simple_oauth

NO_ARCH=	yes

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
