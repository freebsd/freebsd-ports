# New ports collection makefile for:	gaim-rss-rader
# Date created:		8 Aug 2004
# Whom:			mycroft@virgaria.org
#
# $FreeBSD$
#

PORTNAME=	rss-reader
PORTVERSION=	0.1
PORTREVISION=	7
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PKGNAMEPREFIX}${PORTNAME}
PKGNAMEPREFIX=	gaim-
DISTNAME=	${PKGNAMEPREFIX}${PORTNAME}-${PORTVERSION}

MAINTAINER=	mycroft@virgaria.org
COMMENT=	Provides Rss support for Gaim

BUILD_DEPENDS=	${X11BASE}/include/gaim/config.h:${PORTSDIR}/net/gaim
RUN_DEPENDS=	gaim:${PORTSDIR}/net/gaim

IGNORE=	Requires update to work with Gaim 0.82.1

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	gtk20 libxml2
USE_LIBTOOL_VER=15
CONFIGURE_ARGS=	"--with-gaim=${X11BASE}/include/gaim"
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
