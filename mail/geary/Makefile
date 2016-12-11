# Created by: Gustau Perez <gustau.perez@gmail.com>
# $FreeBSD$
#   $MCom: ports/trunk/mail/geary/Makefile 20050 2014-11-10 09:22:41Z gusi $

PORTNAME=	geary
PORTVERSION=	0.10.0
CATEGORIES=	mail gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Mail client for GNOME 3

BUILD_DEPENDS=	vapigen:lang/vala \
		bash:shells/bash
LIB_DEPENDS=	libgmime-2.6.so:mail/gmime26 \
		libwebkitgtk-3.0.so:www/webkit-gtk3 \
		libcanberra-gtk3.so:audio/libcanberra-gtk3 \
		libnotify.so:devel/libnotify \
		libgee-0.8.so:devel/libgee \
		libgcr-3.so:security/gcr

USES=		cmake desktop-file-utils gettext \
		libtool pkgconfig shebangfix tar:xz
USE_GNOME=	gnomedocutils gnomeprefix gtk30 intlhack
SHEBANG_FILES=	desktop/geary-attach
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

GLIB_SCHEMAS=	org.yorba.geary.gschema.xml

post-patch:
		@${REINPLACE_CMD} -e 's|abort $$option||g' \
			${WRKSRC}/configure

.include <bsd.port.mk>
