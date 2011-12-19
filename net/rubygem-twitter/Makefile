# ex:ts=8
# Ports collection makefile for:	rubygem-twitter
# Date created:			Apr 15, 2007
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	twitter
PORTVERSION=	2.0.2
CATEGORIES=	net rubygems
MASTER_SITES=   RG

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Command line twits and an API wrapper

RUN_DEPENDS=	rubygem-simple_oauth>=0.1:${PORTSDIR}/net/rubygem-simple_oauth \
		rubygem-multi_json>=1.0:${PORTSDIR}/devel/rubygem-multi_json \
		rubygem-faraday>=0.7:${PORTSDIR}/www/rubygem-faraday \
		rubygem-activesupport>=2.3.9:${PORTSDIR}/devel/rubygem-activesupport

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
