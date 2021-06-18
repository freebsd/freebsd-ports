# Created by: Koop Mast <kwm@FreeBSD.org>

PORTNAME=	evolution-ews
DISTVERSION=	3.40.2
CATEGORIES=	mail gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Evolution Microsoft Exchange plugin through Exchange Web Services

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	evolution>=3.0.0:mail/evolution
LIB_DEPENDS=	libsoup-2.4.so:devel/libsoup \
		libfribidi.so:converters/fribidi \
		libicuuc.so:devel/icu \
		libmspack.so:archivers/libmspack \
		libsecret-1.so:security/libsecret \
		libnspr4.so:devel/nspr \
		libnss3.so:security/nss \
		libwebkit2gtk-4.0.so:www/webkit2-gtk3 \
		libical.so:devel/libical \
		libjson-glib-1.0.so:devel/json-glib
RUN_DEPENDS=	evolution>=3.0.0:mail/evolution

PORTSCOUT=	limitw:1,even

USES=		bdb:5 compiler:c11 cmake gettext gnome localbase pathfix \
		pkgconfig sqlite tar:xz
USE_GNOME=	cairo gdkpixbuf2 evolutiondataserver3 intltool

.include <bsd.port.mk>
