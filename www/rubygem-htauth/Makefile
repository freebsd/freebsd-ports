# Ports collection makefile for:	gem-color
# Date created:				19 Apr 2008
# Whom:					dirk.meyer@dinoex.sub.org
#
# $FreeBSD$

PORTNAME=	htauth
PORTVERSION=	1.0.3
CATEGORIES=	www rubygems
MASTER_SITES=	RF
MASTER_SITE_SUBDIR=	copiousfreetime

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Replacement for the Apache htdigest and htpasswd

RUN_DEPENDS=	rubygem-highline>=1.5.0:${PORTSDIR}/devel/rubygem-highline

USE_RUBY=	yes
USE_RUBYGEMS=	yes
USE_RAKE=	yes
RUBYGEM_AUTOPLIST=  yes
PLIST_FILES=	bin/htdigest-ruby bin/htpasswd-ruby

.include <bsd.port.mk>
