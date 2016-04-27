# Created by: TAKATSU Tomonari <tota@FreeBSD.org>
# $FreeBSD$

PORTNAME=	em-twitter
PORTVERSION=	0.3.5
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Twitter Streaming API client for EventMachine

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	rubygem-buftok>=0.2:devel/rubygem-buftok \
		rubygem-eventmachine>=1.0:devel/rubygem-eventmachine \
		rubygem-http_parser.rb>=0.6:net/rubygem-http_parser.rb \
		rubygem-simple_oauth>=0.2:net/rubygem-simple_oauth

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

.include <bsd.port.mk>
