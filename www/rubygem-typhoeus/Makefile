# Ports collection makefile for:	rubygem-typhoeus
# Date created:				26 June 2011
# Whom:					Eric Freeman <freebsdports@chillibear.com>
#
# $FreeBSD$
#

PORTNAME=	typhoeus
PORTVERSION=	0.2.4
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	freebsdports@chillibear.com
COMMENT=	Parallel HTTP request library

RUN_DEPENDS=	rubygem-mime-types>=0:${PORTSDIR}/misc/rubygem-mime-types
LIB_DEPENDS=	curl:${PORTSDIR}/ftp/curl

USE_RUBY=		yes
USE_RUBYGEMS=		yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
