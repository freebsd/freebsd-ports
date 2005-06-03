# ex:ts=8
# New ports collection makefile for:	gtkglarea--
# Date created:			Dec 5, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	gtkglareamm
PORTVERSION=	1.1.1
PORTREVISION=	1
CATEGORIES=	x11-toolkits
MASTER_SITES=	http://www.ece.ucdavis.edu/~kenelson/gtk-glarea/dist/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GtkGLArea-- is a wrapper for the GtkGLArea widget

BUILD_DEPENDS=	gm4:${PORTSDIR}/devel/m4
LIB_DEPENDS=	gtkmm.2:${PORTSDIR}/x11-toolkits/gtk-- \
		gtkgl.5:${PORTSDIR}/x11-toolkits/gtkglarea

USE_GL=		yes
USE_GNOME=	gtk12
USE_LIBTOOL_VER=15
USE_REINPLACE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=	--with-lib-GL
INSTALLS_SHLIB=	yes

CPPFLAGS=	-I${LOCALBASE}/include -I${X11BASE}/include ${PTHREAD_CFLAGS}
LDFLAGS=	-L${LOCALBASE}/lib -L${X11BASE}/lib -lGL -lGLU \
		${PTHREAD_LIBS}

post-patch:
	@${REINPLACE_CMD} -e 's|$${CONFIG_SHELL-/bin/sh} $$ac_aux_dir|$$ac_aux_dir|' \
		${WRKSRC}/configure

.include <bsd.port.mk>
