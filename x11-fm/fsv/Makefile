# New ports collection makefile for:   fsv
# Date created:        06 February 2000
# Whom:                Yukihiro Nakai <nakai@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	fsv
PORTVERSION= 	0.9
CATEGORIES=	x11-fm
MASTER_SITES=	http://fox.mit.edu/skunk/soft/src/

MAINTAINER=	sobomax@FreeBSD.org

LIB_DEPENDS=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12 \
		GL.14:${PORTSDIR}/graphics/Mesa3 \
		gtkgl.5:${PORTSDIR}/x11-toolkits/gtkglarea

GTK_CONFIG?=	${X11BASE}/bin/gtk12-config

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-GL-prefix=${X11BASE}/lib
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		GTK_CONFIG="${GTK_CONFIG}" \
		LIBS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
