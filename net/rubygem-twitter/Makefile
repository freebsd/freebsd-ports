# Ports collection makefile for:	rubygem-twitter
# Date created:			Apr 15, 2007
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	twitter
PORTVERSION=	3.6.0
CATEGORIES=	net rubygems
MASTER_SITES=   RG

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Command line twits and an API wrapper

RUN_DEPENDS=	rubygem-faraday>=0.8:${PORTSDIR}/www/rubygem-faraday \
		rubygem-multi_json>=1.3:${PORTSDIR}/devel/rubygem-multi_json \
		rubygem-simple_oauth>=0.1.6:${PORTSDIR}/net/rubygem-simple_oauth

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
