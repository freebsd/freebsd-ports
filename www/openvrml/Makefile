# New ports collection makefile for:	OpenVRML
# Date created:				8 Jan 2001
# Whom:					Marc van Woerkom <3d@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	openvrml
PORTVERSION=	0.10.1
CATEGORIES=	www graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	openvrml

MAINTAINER=	3d@freebsd.org

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.4:${PORTSDIR}/graphics/png

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-jpeg-prefix=${LOCALBASE} \
		--with-png-prefix=${LOCALBASE} \
		--with-MesaGL
CONFIGURE_ENV=	LIBS="-L${X11BASE}/lib -lX11 -lXext -lm -lGL -lGLU -pthread"
USE_GMAKE=	yes
USE_LIBTOOL=	yes
USE_X_PREFIX=	yes
USE_MESA=	yes
INSTALLS_SHLIB=	yes

.include <bsd.port.mk>
