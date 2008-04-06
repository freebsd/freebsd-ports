# Ports collection makefile for:	rubygem-staticmatic
# Date created:				15 November 2007
# Whom:					Robert Gogolok <gogo@cs.uni-sb.de>
#
# $FreeBSD$

PORTNAME=	staticmatic
PORTVERSION=	0.9.3
CATEGORIES=	www rubygems
MASTER_SITES=	${MASTER_SITE_RUBYFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	gogo@cs.uni-sb.de
COMMENT=	Manage static websites using Haml and Sass

RUN_DEPENDS=	rubygem-haml>=1.7.0:${PORTSDIR}/www/rubygem-haml \
		rubygem-mongrel>=1.0.1:${PORTSDIR}/www/rubygem-mongrel

USE_RUBY=	yes
USE_RUBYGEMS=	yes

.include <bsd.port.mk>
