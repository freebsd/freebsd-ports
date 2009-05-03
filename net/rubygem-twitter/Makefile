# ex:ts=8
# Ports collection makefile for:	rubygem-twitter
# Date created:			Apr 15, 2007
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	twitter
PORTVERSION=	0.6.8
CATEGORIES=	net rubygems
MASTER_SITES=	RF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Command line twits and an API wrapper

RUN_DEPENDS=	rubygem-oauth>=0.3.2:${PORTSDIR}/net/rubygem-oauth \
		rubygem-mash>=0.0.3:${PORTSDIR}/devel/rubygem-mash \
		rubygem-httparty>=0.4.3:${PORTSDIR}/www/rubygem-httparty

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
