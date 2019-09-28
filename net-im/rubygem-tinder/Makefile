# $FreeBSD$

PORTNAME=	tinder
PORTVERSION=	1.10.1
PORTREVISION=	2
CATEGORIES=	net-im rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby API for interfacing with Campfire

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-eventmachine>=1.0<2:devel/rubygem-eventmachine \
		rubygem-faraday>=0.9.0<1:www/rubygem-faraday \
		rubygem-faraday_middleware>=0.9<1:www/rubygem-faraday_middleware \
		rubygem-hashie>=1.0:devel/rubygem-hashie \
		rubygem-json1>=1.8.0<1.9:devel/rubygem-json1 \
		rubygem-mime-types>=0:misc/rubygem-mime-types \
		rubygem-multi_json>=1.7<2:devel/rubygem-multi_json \
		rubygem-twitter-stream>=0.1<1:net/rubygem-twitter-stream

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
