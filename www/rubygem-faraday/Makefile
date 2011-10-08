# Ports collection makefile for:	rubygem-faraday
# Date created:				04 March 2011
# Whom:					Cheng-Lung Sung <clsung@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	faraday
PORTVERSION=	0.7.5
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	A HTTP/REST API client library in Ruby

RUN_DEPENDS=	rubygem-rack>=1.1.0:${PORTSDIR}/www/rubygem-rack \
		rubygem-multipart-post>=1.1.0:${PORTSDIR}/www/rubygem-multipart-post \
		rubygem-addressable>=2.2.4:${PORTSDIR}/www/rubygem-addressable

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
