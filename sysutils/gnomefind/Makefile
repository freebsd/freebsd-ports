# New ports collection makefile for:	gnomefind
# Date created:		26 May 2000
# Whom:			Maxim Sobolev
#
# $FreeBSD$
#

PORTNAME=	gnomefind
PORTVERSION= 	1.0
CATEGORIES=	sysutils gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	gnome-find
DISTNAME=	gnome-find-${PORTVERSION}

MAINTAINER=	sobomax@FreeBSD.org

LIB_DEPENDS=	gnome.4:${PORTSDIR}/x11/gnomelibs \
		glade.4:${PORTSDIR}/devel/libglade \
		Xpm.4:${PORTSDIR}/graphics/xpm
RUN_DEPENDS=	gnomecc:${PORTSDIR}/sysutils/gnomecontrolcenter

GLIB_CONFIG?=	${LOCALBASE}/bin/glib12-config
GTK_CONFIG?=	${X11BASE}/bin/gtk12-config

CONFIGURE_ENV=	GLIB_CONFIG="${GLIB_CONFIG}" \
		GTK_CONFIG="${GTK_CONFIG}" \
		CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-lgnuregex -L${LOCALBASE}/lib"

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes

MAN1=		gnome-find.1

.include <bsd.port.mk>
