# New ports collection makefile for:	rubygem-twitter-stream
# Date created:		2010-11-03
# Whom:			TAKATSU Tomonari <tota@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	twitter-stream
PORTVERSION=	0.1.11
CATEGORIES=	net rubygems
MASTER_SITES=	RG

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Twitter realtime API client

RUN_DEPENDS=	rubygem-eventmachine>=0.12.8:${PORTSDIR}/devel/rubygem-eventmachine \
		rubygem-roauth>=0.0.2:${PORTSDIR}/security/rubygem-roauth

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
