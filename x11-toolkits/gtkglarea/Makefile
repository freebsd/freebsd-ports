# New ports collection makefile for:   gtkglarea
# Date created:        1 August 1999
# Whom:                Michael Sardo <jaeger16@yahoo.com>
#
# $FreeBSD$
#

PORTNAME=	gtkglarea
PORTVERSION= 	1.2.1
CATEGORIES=	x11-toolkits
MASTER_SITES=	http://www.student.oulu.fi/~jlof/gtkglarea/download/

MAINTAINER=	jaeger16@yahoo.com

LIB_DEPENDS=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12 \
		GL.14:${PORTSDIR}/graphics/Mesa3

FETCH_BEFORE_ARGS=	-b
USE_LIBTOOL=	yes
CONFIGURE_ARGS=  --with-lib-MesaGL
CONFIGURE_ENV=	LOCALBASE=${LOCALBASE} GTK_CONFIG=${X11BASE}/bin/gtk12-config

post-install:
	@${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
