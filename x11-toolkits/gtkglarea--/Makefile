# ex:ts=8
# New ports collection makefile for:	gtkglarea--
# Date created:			Dec 5, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	gtkglareamm
PORTVERSION=	1.1.1
CATEGORIES=	x11-toolkits
MASTER_SITES=	http://www.ece.ucdavis.edu/~kenelson/gtk-glarea/dist/

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	gtkmm.2:${PORTSDIR}/x11-toolkits/gtk-- \
		gtkgl.5:${PORTSDIR}/x11-toolkits/gtkglarea

USE_GNOMENG=	yes
USE_GNOME=	gtk12
USE_MESA=	yes
USE_LIBTOOL=	yes
CONFIGURE_ENV=	CPPFLAGS="${PTHREAD_CFLAGS}" LDFLAGS="${PTHREAD_LIBS}"
CONFIGURE_ARGS=	--with-lib-GL
INSTALLS_SHLIB=	yes

.include <bsd.port.mk>
