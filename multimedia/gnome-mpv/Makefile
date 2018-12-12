# $FreeBSD$

PORTNAME=	gnome-mpv
PORTVERSION=	0.15
PORTREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	https://github.com/${PORTNAME}/${PORTNAME}/releases/download/v${PORTVERSION}/

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Simple GTK+ frontend for mpv

LICENSE=	GPLv3+

LIB_DEPENDS=	libepoxy.so:graphics/libepoxy \
		libmpv.so:multimedia/mpv

USES=		compiler:c11 desktop-file-utils gettext-tools gmake pkgconfig tar:xz
USE_GNOME=	cairo gtk30
GNU_CONFIGURE=	yes
GLIB_SCHEMAS=	io.github.GnomeMpv.gschema.xml \
		org.gnome-mpv.gschema.xml
INSTALLS_ICONS=	yes
LDFLAGS+=	-Wl,--as-needed # gdkpixbuf2

.include <bsd.port.mk>
