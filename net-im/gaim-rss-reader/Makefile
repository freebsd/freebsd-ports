# New ports collection makefile for:	gaim-rss-rader
# Date created:		8 Aug 2004
# Whom:			mycroft@virgaria.org
#
# $FreeBSD$
#

PORTNAME=	rss-reader
PORTVERSION=	0.1
PORTREVISION=	10
CATEGORIES=	net-im
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PKGNAMEPREFIX}${PORTNAME}
PKGNAMEPREFIX=	gaim-
DISTNAME=	${PKGNAMEPREFIX}${PORTNAME}-${PORTVERSION}

MAINTAINER=	mycroft@virgaria.org
COMMENT=	Provides Rss support for Gaim

BUILD_DEPENDS=	${LOCALBASE}/include/gaim/config.h:${PORTSDIR}/net-im/gaim
RUN_DEPENDS=	gaim:${PORTSDIR}/net-im/gaim

IGNORE=	Requires update to work with Gaim 0.82.1
DEPRECATED=	${IGNORE}
EXPIRATION_DATE=2006-12-01

USE_XLIB=	yes
USE_GMAKE=	yes
USE_GNOME=	gtk20 libxml2
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	"--with-gaim=${LOCALBASE}/include/gaim"
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
