# New ports collection makefile for:	oleo
# Date created:		3 September 1994
# Whom:			mr
#
# $FreeBSD$
#

PORTNAME=	oleo
PORTVERSION=	1.99.14
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	intl.1:${PORTSDIR}/devel/gettext
.if defined(WITH_MOTIF)
LIB_DEPENDS+=	plot.3:${PORTSDIR}/graphics/plotutils \
		Xbae.7:${PORTSDIR}/x11-toolkits/xbae
.endif

USE_XLIB=	yes
USE_AUTOCONF=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		LIBS="-L${LOCALBASE}/lib -L${X11BASE}/lib"
CONFIGURE_ARGS=	--with-x --without-xlt \
		--without-xmhtml --without-SciPlot

.if defined(WITH_MOTIF)
USE_MOTIF=	yes
CONFIGURE_ARGS+=	--with-motif
.else
CONFIGURE_ARGS+=	--without-motif
.endif

.include <bsd.port.mk>
