# New ports collection makefile for:	pan
# Version required:			0.6.5
# Date created:				07 August 1999
# Whom:					Chris D. Faulhaber <jedgar@fxp.org>
#
# $FreeBSD$
#

DISTNAME=	pan-0.6.5
CATEGORIES=	news gnome
MASTER_SITES=	ftp://source.rebelbase.com/pub/pan/

MAINTAINER=	jedgar@fxp.org

LIB_DEPENDS=	gnome.3:${PORTSDIR}/x11/gnomelibs

GLIB_CONFIG?=	${LOCALBASE}/bin/glib12-config
GTK_CONFIG?=	${X11BASE}/bin/gtk12-config

USE_BZIP2=	yes
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-x
CONFIGURE_ENV+=	CFLAGS="-I${LOCALBASE}/include ${CFLAGS}" \
		GLIB_CONFIG="${GLIB_CONFIG}" \
		GTK_CONFIG="${GTK_CONFIG}" \
		LIBS="-L${LOCALBASE}/lib"

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 300000
pre-fetch:
	@${ECHO}
	@${ECHO} "Must have FreeBSD-3.0 or greater due to"
	@${ECHO} "the use of the thread library."
	@${ECHO}
.endif

.include <bsd.port.mk>
