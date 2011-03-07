# ex:ts=8
# Ports collection makefile for:	rubygem-twitter
# Date created:			Apr 15, 2007
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	twitter
PORTVERSION=	1.1.2
CATEGORIES=	net rubygems
MASTER_SITES=   RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Command line twits and an API wrapper

RUN_DEPENDS=	rubygem-simple_oauth>=0.1.3:${PORTSDIR}/net/rubygem-simple_oauth \
		rubygem-multi_xml>=0.2.0:${PORTSDIR}/textproc/rubygem-multi_xml \
		rubygem-multi_json>=0.0.5:${PORTSDIR}/devel/rubygem-multi_json \
		rubygem-faraday_middleware>=0.3.1:${PORTSDIR}/www/rubygem-faraday_middleware \
		rubygem-faraday>=0.5.4:${PORTSDIR}/www/rubygem-faraday \
		rubygem-hashie>=1.0.0:${PORTSDIR}/devel/rubygem-hashie

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
