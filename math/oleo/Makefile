# New ports collection makefile for:	oleo
# Version required:	1.99.5
# Date created:		3 September 1994
# Whom:			mr
#
# $FreeBSD$
#

DISTNAME=	oleo-1.99.5
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	oleo

MAINTAINER=	ports@FreeBSD.org

BUILD_DEPENDS=	gettext:${PORTSDIR}/devel/gettext

USE_XLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		LIBS="-L${LOCALBASE}/lib -L${X11BASE}/lib"
CONFIGURE_ARGS=	--with-x --without-motif \
		--without-Xbae --without-XmHTML \
		--without-xlt --without-SciPlot

.include <bsd.port.mk>
