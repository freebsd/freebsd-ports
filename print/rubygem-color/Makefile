# Ports collection makefile for:	gem-color
# Date created:				29 Mrz 2007
# Whom:					dirk.meyer@dinoex.sub.org
#
# $FreeBSD$

PORTNAME=	color
PORTVERSION=	1.4.0
CATEGORIES=	print rubygems
MASTER_SITES=	${MASTER_SITE_RUBYFORGE}
MASTER_SITE_SUBDIR=	color
DISTNAME=	color-${PORTVERSION}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Provides colour space definition and manpiulation

BUILD_DEPENDS=	rubygem-archive-tar-minitar>=0.5.1:${PORTSDIR}/archivers/rubygem-archive-tar-minitar \
		rubygem-hoe>=1.3.0:${PORTSDIR}/devel/rubygem-hoe
RUN_DEPENDS=	${BUILD_DEPENDS}

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/ruby-gems/Makefile.common"
.include <bsd.port.post.mk>
