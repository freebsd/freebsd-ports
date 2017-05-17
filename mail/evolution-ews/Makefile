# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	evolution-ews
PORTVERSION=	3.22.6
CATEGORIES=	mail gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Evolution Microsoft Exchange plugin through Exchange Web Services

BUILD_DEPENDS=	evolution>=3.0.0:mail/evolution
LIB_DEPENDS=	libsoup-2.4.so:devel/libsoup \
		libmspack.so:archivers/libmspack \
		libsecret-1.so:security/libsecret \
		libnspr4.so:devel/nspr \
		libnss3.so:security/nss \
		libwebkit2gtk-4.0.so:www/webkit2-gtk3 \
		libical.so:devel/libical
RUN_DEPENDS=	evolution>=3.0.0:mail/evolution

PORTSCOUT=	limitw:1,even

USES=		bdb:5 gettext gmake gnome libtool localbase pathfix \
		pkgconfig sqlite tar:xz
USE_GNOME=	atk cairo evolutiondataserver3 gdkpixbuf2 gtk30 glib20 \
		intltool libxml2 pango
GNU_CONFIGURE=	yes
USE_OPENLDAP=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--datarootdir=${PREFIX}/share \
		--localedir=${PREFIX}/share/locale \
		--prefix=${PREFIX}
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
