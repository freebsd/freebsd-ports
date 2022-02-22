# Created by: Mike Krutov <neko@takino.org>

PORTNAME=	girara
PORTVERSION=	0.3.7
CATEGORIES=	x11-toolkits graphics
MASTER_SITES=	https://git.pwmt.org/pwmt/${PORTNAME}/-/archive/${DISTVERSION}/ \
		https://pwmt.org/projects/girara/download/

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	GTK3 Interface Library for Zathura PDF Viewer

USES=		compiler:c11 gnome meson pathfix pkgconfig tar:xz
USE_GNOME=	cairo gdkpixbuf2 glib20 gtk30

PATHFIX_MAKEFILEIN=	Makefile
LIBDIR=			${PREFIX}/lib

OPTIONS_DEFINE=		JSONC NLS NOTIFY
OPTIONS_DEFAULT=	NOTIFY
JSONC_DESC=		Support json configuration dump

OPTIONS_SUB=		yes

JSONC_LIB_DEPENDS=	libjson-c.so:devel/json-c
JSONC_MESON_ENABLED=	json

NLS_USES=		gettext

NOTIFY_LIB_DEPENDS=	libnotify.so:devel/libnotify
NOTIFY_MESON_ENABLED=	notify

post-patch-NLS-off: .SILENT
	${REINPLACE_CMD} -e "/subdir('po')/d" \
		${WRKSRC}/meson.build

.include <bsd.port.mk>
