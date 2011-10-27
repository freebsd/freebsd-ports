# New ports collection makefile for:	rubygem-webmock
# Date created:		21 September 2010
# Whom:			Philip M. Gollucci <pgollucci@p6m7g8.com>
#
# $FreeBSD$
#

PORTNAME=	webmock
PORTVERSION=	1.7.7
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Allows stubbing HTTP requests and setting expectations on the requests

RUN_DEPENDS=	rubygem-crack>=0.1.7:${PORTSDIR}/devel/rubygem-crack \
		rubygem-addressable>=2.2:${PORTSDIR}/www/rubygem-addressable

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
