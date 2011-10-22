# New ports collection makefile for:	rubygem-tweetstream
# Date created:		2010-11-17
# Whom:			TAKATSU Tomonari <tota@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	tweetstream
PORTVERSION=	1.1.2
CATEGORIES=	net rubygems
MASTER_SITES=	RG

MAINTAINER=	tota@FreeBSD.org
COMMENT=	TweetStream provides simple Ruby access to Twitter\'s Streaming API

RUN_DEPENDS=	rubygem-twitter-stream>=0.1.14:${PORTSDIR}/net/rubygem-twitter-stream \
		rubygem-daemons>=1.1.4:${PORTSDIR}/devel/rubygem-daemons \
		rubygem-multi_json>=1.0.3:${PORTSDIR}/devel/rubygem-multi_json

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

OPTIONS=	JSON_PURE	"JSON implementation in pure Ruby support"	Off \
		YAJL_RUBY	"yajl-ruby support"	Off

.include <bsd.port.options.mk>

.if defined(WITH_JSON_PURE)
RUN_DEPENDS+=	rubygem-json_pure>=0:${PORTSDIR}/devel/rubygem-json_pure
.endif

.if defined(WITH_YAJL_RUBY)
RUN_DEPENDS+=	rubygem-yajl-ruby>=0:${PORTSDIR}/devel/rubygem-yajl-ruby
.endif

.include <bsd.port.mk>
