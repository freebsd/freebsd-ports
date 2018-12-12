# Created by: Mike Krutov <neko@takino.org>
# $FreeBSD$

PORTNAME=	girara
PORTVERSION=	0.3.1
PORTREVISION=	1
CATEGORIES=	x11-toolkits graphics
MASTER_SITES=	https://pwmt.org/projects/girara/download/ \
		http://www.madpilot.net/~mad/pwmt.org/

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	GTK3 Interface Library for Zathura PDF Viewer

USES=		compiler:c11 meson pathfix pkgconfig tar:xz
PATHFIX_MAKEFILEIN=	Makefile
USE_GNOME=	cairo gdkpixbuf2 glib20 gtk30
USE_LDCONFIG=	yes
LIBDIR=		${PREFIX}/lib

OPTIONS_DEFINE=		JSONC NLS NOTIFY
OPTIONS_DEFAULT=	NOTIFY
JSONC_DESC=		Support json configuration dump

OPTIONS_SUB=		yes

JSONC_LIB_DEPENDS=	libjson-c.so:devel/json-c
JSONC_MESON_TRUE=	enable-json

NLS_USES=		gettext

NOTIFY_LIB_DEPENDS=	libnotify.so:devel/libnotify
NOTIFY_MESON_TRUE=	enable-notify

post-patch-NLS-off: .SILENT
	${REINPLACE_CMD} -e "/subdir('po')/d" \
		${WRKSRC}/meson.build

.include <bsd.port.mk>
