# New ports collection makefile for:	rcalc
# Date created:				28 October 1999
# Whom:					Chris D. Faulhaber <jedgar@fxp.org>
#
# $FreeBSD$
#

PORTNAME=	rcalc
PORTVERSION=	0.1
CATEGORIES=	math gnome
MASTER_SITES=	http://members.xoom.com/ratsoft/download/
DISTNAME=	rCalc-${PORTVERSION}

MAINTAINER=	jedgar@fxp.org

LIB_DEPENDS=	gnome.3:${PORTSDIR}/x11/gnomelibs

FETCH_BEFORE_ARGS+= -b	# members.xoom.com is broken

GTK_CONFIG?=	${X11BASE}/bin/gtk12-config

USE_X_PREFIX=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-x
CONFIGURE_ENV+=	CFLAGS="-I${LOCALBASE}/include ${CFLAGS}" \
		GTK_CONFIG="${GTK_CONFIG}" \
		LIBS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
