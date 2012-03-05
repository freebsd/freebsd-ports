# New ports collection makefile for:	rubygem-tweetstream
# Date created:		2010-11-17
# Whom:			TAKATSU Tomonari <tota@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	tweetstream
PORTVERSION=	1.1.4
CATEGORIES=	net rubygems
MASTER_SITES=	RG

MAINTAINER=	tota@FreeBSD.org
COMMENT=	TweetStream provides simple Ruby access to Twitter\'s Streaming API

RUN_DEPENDS=	rubygem-twitter-stream>=0.1.14:${PORTSDIR}/net/rubygem-twitter-stream \
		rubygem-daemons>=1.1:${PORTSDIR}/devel/rubygem-daemons \
		rubygem-multi_json>=1.0:${PORTSDIR}/devel/rubygem-multi_json

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
