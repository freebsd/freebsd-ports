# ex:ts=8
# Ports collection makefile for:	rubygem-twitter
# Date created:			Apr 15, 2007
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	twitter
PORTVERSION=	0.7.0
CATEGORIES=	net rubygems
MASTER_SITES=   ${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR= pgollucci

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Command line twits and an API wrapper

RUN_DEPENDS=	rubygem-oauth>=0.3.4:${PORTSDIR}/net/rubygem-oauth \
		rubygem-mash>=0.0.3:${PORTSDIR}/devel/rubygem-mash \
		rubygem-httparty>=0.4.3:${PORTSDIR}/www/rubygem-httparty \
		rubygem-hoe>=0.12.2:${PORTSDIR}/devel/rubygem-hoe

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
