# Created by: Mike Krutov <neko@takino.org>
# $FreeBSD$

PORTNAME=	girara
PORTVERSION=	0.2.8
PORTREVISION=	1
CATEGORIES=	x11-toolkits graphics
MASTER_SITES=	https://pwmt.org/projects/girara/download/ \
		http://www.madpilot.net/~mad/pwmt.org/

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	GTK3 Interface Library for Zathura PDF Viewer

USES=		gmake pathfix pkgconfig
PATHFIX_MAKEFILEIN=	Makefile
USE_GNOME=	cairo gdkpixbuf2 glib20 gtk30
USE_LDCONFIG=	yes
USE_CSTD=	gnu99
LIBDIR=		${PREFIX}/lib
MAKE_ENV+=	SFLAGS=${STRIP} \
		VERBOSE=1

OPTIONS_DEFINE=		JSONC NLS NOTIFY
OPTIONS_DEFAULT=	NOTIFY
JSONC_DESC=		Support json configuration dump

OPTIONS_SUB=		yes

JSONC_LIB_DEPENDS=	libjson-c.so:devel/json-c
JSONC_MAKE_ENV_OFF=		WITH_JSON=0

NLS_USES=		gettext

NOTIFY_LIB_DEPENDS=	libnotify.so:devel/libnotify
NOTIFY_MAKE_ENV_OFF=	WITH_LIBNOTIFY=0

post-patch:	.SILENT
	${REINPLACE_CMD} -e 's|^\(CFLAGS +=\) -std=c11|\1|' \
		${WRKSRC}/config.mk

post-patch-NLS-off: .SILENT
	${REINPLACE_CMD} -e '/-C po/d' \
		${WRKSRC}/Makefile

.include <bsd.port.mk>
