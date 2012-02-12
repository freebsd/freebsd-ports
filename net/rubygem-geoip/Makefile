# New ports collection makefile for:	rubygem-geoip
# Date created:		2009-06-15
# Whom:			Renato Botelho <garga@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	geoip
PORTVERSION=	1.1.2
CATEGORIES=	net rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Geoip implementation for rubygems

RUN_DEPENDS=	geoiplookup:${PORTSDIR}/net/GeoIP

USE_RUBY=		yes
USE_RUBYGEMS=		yes
RUBYGEM_AUTOPLIST=	yes

PLIST_FILES=	bin/geoip

.include <bsd.port.mk>
