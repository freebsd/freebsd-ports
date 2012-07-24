# Ports collection makefile for:	rubygem-em-http-request
# Date created:				13 Dec 2011
# Whom:					Scott Sanders <scott@jssjr.com>
#
# $FreeBSD$
#

PORTNAME=	em-http-request
PORTVERSION=	0.2.15
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	EventMachine based, async HTTP Request client

RUN_DEPENDS=	rubygem-addressable>=2.0.0:${PORTSDIR}/www/rubygem-addressable \
		rubygem-escape_utils>=0:${PORTSDIR}/textproc/rubygem-escape_utils \
		rubygem-eventmachine>=0.12.9:${PORTSDIR}/devel/rubygem-eventmachine

USE_RUBY=		yes
USE_RUBYGEMS=		yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
