# New ports collection makefile for:	meanwhile-gaim
# Date created:		24 June 2004
# Whom:		 	marcus@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	meanwhile
PORTVERSION=	0.81
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMEPREFIX=	gaim-
DISTNAME=	${PKGNAMEPREFIX}${PORTNAME}-${PORTVERSION}

MAINTAINER=	marcus@FreeBSD.org
COMMENT=	Provides Lotus Sametime support for Gaim

BUILD_DEPENDS=	${X11BASE}/include/gaim/config.h:${PORTSDIR}/net/gaim
LIB_DEPENDS=	meanwhile.0:${PORTSDIR}/net/meanwhile
RUN_DEPENDS=	gaim:${PORTSDIR}/net/gaim

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehack gtk20
USE_LIBTOOL_VER=15
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
