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

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	vapigen:lang/vala \
		bash:shells/bash
LIB_DEPENDS=	libgmime-2.6.so:mail/gmime26 \
		libwebkitgtk-3.0.so:www/webkit-gtk3 \
		libcanberra-gtk3.so:audio/libcanberra-gtk3 \
		libnotify.so:devel/libnotify \
		libgee-0.8.so:devel/libgee \
		libgcr-3.so:security/gcr

USES=		cmake desktop-file-utils gettext \
		libtool localbase:ldflags pkgconfig shebangfix tar:xz
USE_GNOME=	gnomedocutils gnomeprefix gtk30 intlhack
SHEBANG_FILES=	desktop/geary-attach
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes
CMAKE_ARGS=	-DNO_FATAL_WARNINGS:BOOL=ON

GLIB_SCHEMAS=	org.yorba.geary.gschema.xml

post-patch:
	@${REINPLACE_CMD} -e 's|abort $$option||g' \
		${WRKSRC}/configure

.include <bsd.port.mk>
