# New ports collection makefile for:	gaim-openq
# Date created:		2004-10-12
# Whom:		 	hamigua@hotpop.com
#
# $FreeBSD$
#

PORTNAME=	openq
PORTVERSION=	0.3.0
PORTREVISION=	10
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMEPREFIX=	gaim-
DISTNAME=	OpenQ-${PORTVERSION}.p4

MAINTAINER=	hamigua@hotpop.com
COMMENT=	A QQ-liked protocol plugin for Gaim

BUILD_DEPENDS=	${X11BASE}/include/gaim/config.h:${PORTSDIR}/net/gaim
RUN_DEPENDS=	gaim:${PORTSDIR}/net/gaim

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehack gtk20
USE_LIBTOOL_VER=15
CONFIGURE_ARGS=	--enable-static=yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib"

PLIST_SUB=	PATH_SUB=${DISTNAME}

.include <bsd.port.mk>
