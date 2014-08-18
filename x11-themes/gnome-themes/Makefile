# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/x11-themes/gnome-themes/Makefile 19813 2014-08-15 19:44:33Z gusi $

PORTNAME=	gnome-themes
PORTVERSION=	2.32.1
CATEGORIES=	x11-themes gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Collection of themes and icons for GNOME2

BUILD_DEPENDS=	gtk-engines2>=2.15.0:${PORTSDIR}/x11-themes/gtk-engines2 \
		icon-naming-utils>=0.8.7:${PORTSDIR}/x11-themes/icon-naming-utils
RUN_DEPENDS=	gtk-engines2>=2.15.0:${PORTSDIR}/x11-themes/gtk-engines2

CONFLICTS=	clearlooks-metacity-0.* gnome-themes-standard-3.[0-9]*

USES=		gettext gmake libtool pathfix pkgconfig tar:bzip2
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
USE_GNOME=	gnomeprefix intlhack metacity gtk20
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
