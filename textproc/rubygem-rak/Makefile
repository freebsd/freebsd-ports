# Ports collection makefile for:	rubygem-rak
# Date created:				12 November 2007
# Whom:					Robert Gogolok <gogo@cs.uni-sb.de>
#
# $FreeBSD$

PORTNAME=	rak
PORTVERSION=	1.0
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG

MAINTAINER=	gogo@cs.uni-sb.de
COMMENT=	A grep replacement in pure Ruby

BUILD_DEPENDS=	rubygem-hoe>=1.3.0:${PORTSDIR}/devel/rubygem-hoe
RUN_DEPENDS=	rubygem-hoe>=1.3.0:${PORTSDIR}/devel/rubygem-hoe

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

PLIST_FILES=	bin/rak

.include <bsd.port.mk>
