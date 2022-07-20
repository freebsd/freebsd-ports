PORTNAME=	twitter-stream
PORTVERSION=	0.1.16
PORTREVISION=	2
CATEGORIES=	net rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Twitter realtime API client

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-eventmachine>=0.12.8:devel/rubygem-eventmachine \
		rubygem-http_parser.rb>=0.5.1:net/rubygem-http_parser.rb \
		rubygem-simple_oauth>=0.1.4:net/rubygem-simple_oauth

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
