# Created by: TAKATSU Tomonari <tota@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tweetstream
PORTVERSION=	2.5.0
CATEGORIES=	net rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	TweetStream provides simple Ruby access to Twitter\'s Streaming API

LICENSE=	MIT

RUN_DEPENDS=	rubygem-daemons>=1.1:${PORTSDIR}/devel/rubygem-daemons \
		rubygem-em-http-request>=1.0.2:${PORTSDIR}/www/rubygem-em-http-request \
		rubygem-em-twitter>=0.2:${PORTSDIR}/www/rubygem-em-twitter \
		rubygem-twitter>=4.5:${PORTSDIR}/net/rubygem-twitter \
		rubygem-yajl-ruby>=1.1.0:${PORTSDIR}/devel/rubygem-yajl-ruby

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
