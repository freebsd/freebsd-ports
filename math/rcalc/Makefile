# New ports collection makefile for:	rcalc
# Date created:				28 October 1999
# Whom:					Chris D. Faulhaber <jedgar@fxp.org>
#
# $FreeBSD$
#

PORTNAME=	rcalc
PORTVERSION=	0.2.1
CATEGORIES=	math gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	rCalc-${PORTVERSION}

MAINTAINER=	jedgar@FreeBSD.org

LIB_DEPENDS=	gnome.4:${PORTSDIR}/x11/gnomelibs

GTK_CONFIG?=	${X11BASE}/bin/gtk12-config

USE_X_PREFIX=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-x
CONFIGURE_ENV+=	CFLAGS="-I${LOCALBASE}/include ${CFLAGS}" \
		GTK_CONFIG="${GTK_CONFIG}" \
		LIBS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
