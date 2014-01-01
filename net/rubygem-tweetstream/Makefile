# Created by: TAKATSU Tomonari <tota@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tweetstream
PORTVERSION=	2.6.0
CATEGORIES=	net rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	TweetStream provides simple Ruby access to Twitter\'s Streaming API

LICENSE=	MIT

RUN_DEPENDS=	rubygem-daemons>=1.1:${PORTSDIR}/devel/rubygem-daemons \
		rubygem-em-http-request>=1.1.1:${PORTSDIR}/www/rubygem-em-http-request \
		rubygem-em-twitter>=0.3:${PORTSDIR}/www/rubygem-em-twitter \
		rubygem-multi_json>=1.3:${PORTSDIR}/devel/rubygem-multi_json \
		rubygem-twitter>=4.8:${PORTSDIR}/net/rubygem-twitter

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
