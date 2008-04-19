# Ports collection makefile for:	gem-color
# Date created:				19 Apr 2008
# Whom:					dirk.meyer@dinoex.sub.org
#
# $FreeBSD$

PORTNAME=	htauth
PORTVERSION=	1.0.1
CATEGORIES=	www rubygems
MASTER_SITES=	${MASTER_SITE_RUBYFORGE}
MASTER_SITE_SUBDIR=	copiousfreetime

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Replacement for the Apache htdigest and htpasswd

BUILD_DEPENDS=	rubygem-highline>=1.4.0:${PORTSDIR}/devel/rubygem-highline
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_RUBY=	yes
USE_RUBYGEMS=	yes
USE_RAKE=	yes

.include <bsd.port.mk>
