# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	evolution-ews
PORTVERSION=	3.24.2
PORTREVISION=	1
CATEGORIES=	mail gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Evolution Microsoft Exchange plugin through Exchange Web Services

BUILD_DEPENDS=	evolution>=3.0.0:mail/evolution
LIB_DEPENDS=	libsoup-2.4.so:devel/libsoup \
		libicuuc.so:devel/icu \
		libmspack.so:archivers/libmspack \
		libsecret-1.so:security/libsecret \
		libnspr4.so:devel/nspr \
		libnss3.so:security/nss \
		libwebkit2gtk-4.0.so:www/webkit2-gtk3 \
		libical.so:devel/libical
RUN_DEPENDS=	evolution>=3.0.0:mail/evolution

PORTSCOUT=	limitw:1,even

USES=		bdb:5 cmake gettext gnome localbase pathfix \
		pkgconfig sqlite tar:xz
USE_GNOME=	cairo gdkpixbuf2 evolutiondataserver3 intltool

.include <bsd.port.mk>
