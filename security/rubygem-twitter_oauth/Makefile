# New ports collection makefile for:	rubygem-twitter_oauth
# Date created:		2011-07-31
# Whom:			TAKATSU Tomonari <tota@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	twitter_oauth
PORTVERSION=	0.4.3
CATEGORIES=	security rubygems
MASTER_SITES=	RG

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Twitter OAuth REST API client library for Ruby

RUN_DEPENDS=	rubygem-json>=1.1.9:${PORTSDIR}/devel/rubygem-json \
		rubygem-mime-types>=1.16:${PORTSDIR}/misc/rubygem-mime-types \
		rubygem-oauth>=0.4.1:${PORTSDIR}/net/rubygem-oauth

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
