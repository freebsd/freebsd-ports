# Created by: Oliver Lehmann (oliver@FreeBSD.org)
# $FreeBSD$

PORTNAME=	xfce4-dict
PORTVERSION=	0.8.0
CATEGORIES=	textproc xfce
MASTER_SITES=	XFCE/src/apps/${PORTNAME}/${PORTVERSION:R}
PKGNAMESUFFIX=	-plugin
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Xfce4 plugin to query different dictionaries

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
USES=		gettext gmake libtool pkgconfig tar:bzip2 xfce:gtk3
USE_GNOME=	glib20 gtk30 intltool cairo
USE_XFCE=	panel
USE_XORG=	x11
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
