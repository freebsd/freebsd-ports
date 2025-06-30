PORTNAME=	evolution-ews
DISTVERSION=	3.56.2
PORTREVISION=	1
CATEGORIES=	mail gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Evolution Microsoft Exchange plugin through Exchange Web Services
WWW=		https://gitlab.gnome.org/GNOME/evolution-ews

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	evolution>0:mail/evolution
LIB_DEPENDS=	libsoup-3.0.so:devel/libsoup3 \
		libmspack.so:archivers/libmspack \
		libsecret-1.so:security/libsecret \
		libnspr4.so:devel/nspr \
		libnss3.so:security/nss \
		libical.so:devel/libical \
		libjson-glib-1.0.so:devel/json-glib \
		libwebkit2gtk-4.1.so:www/webkit2-gtk@41
RUN_DEPENDS=	evolution>0:mail/evolution

USES=		compiler:c11 cmake gettext gnome localbase pathfix \
		pkgconfig sqlite tar:xz
USE_GNOME=	cairo gdkpixbuf glib20 gtk30 evolutiondataserver3 \
		intltool:build

.include <bsd.port.mk>
