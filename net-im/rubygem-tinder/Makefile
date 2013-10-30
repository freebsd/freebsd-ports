# $FreeBSD$

PORTNAME=	tinder
PORTVERSION=	1.9.3
CATEGORIES=	net-im rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby API for interfacing with Campfire

RUN_DEPENDS=	rubygem-json>=1.8.0:${PORTSDIR}/devel/rubygem-json \
		rubygem-eventmachine>=1.0:${PORTSDIR}/devel/rubygem-eventmachine \
		rubygem-faraday>=0.8:${PORTSDIR}/www/rubygem-faraday\
		rubygem-faraday_middleware>=0.9:${PORTSDIR}/www/rubygem-faraday_middleware \
		rubygem-hashie>=1.0:${PORTSDIR}/devel/rubygem-hashie \
		rubygem-mime-types>=1.19:${PORTSDIR}/misc/rubygem-mime-types \
		rubygem-multi_json>=1.7:${PORTSDIR}/devel/rubygem-multi_json \
		rubygem-twitter-stream>=0.1:${PORTSDIR}/net/rubygem-twitter-stream

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes


.include <bsd.port.mk>
