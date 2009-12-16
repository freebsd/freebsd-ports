# Ports collection makefile for:	rubygem-staticmatic
# Date created:				15 November 2007
# Whom:					Robert Gogolok <gogo@cs.uni-sb.de>
#
# $FreeBSD$

PORTNAME=	staticmatic
PORTVERSION=	0.10.6
CATEGORIES=	www rubygems
MASTER_SITES=	RF

MAINTAINER=	gogo@cs.uni-sb.de
COMMENT=	Manage static websites using Haml and Sass

RUN_DEPENDS=	rubygem-haml>=2.0.0:${PORTSDIR}/www/rubygem-haml \
		rubygem-mongrel>=1.0.1:${PORTSDIR}/www/rubygem-mongrel

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

PLIST_FILES=	bin/staticmatic

.include <bsd.port.mk>
