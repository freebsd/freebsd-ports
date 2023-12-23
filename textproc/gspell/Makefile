PORTNAME=	gspell
PORTVERSION=	1.10.0
PORTREVISION=	5
CATEGORIES=	textproc
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Spell checking for GTK
WWW=		https://gitlab.gnome.org/GNOME/gspell

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libenchant-2.so:textproc/enchant2 \
		libfribidi.so:converters/fribidi \
		libicudata.so:devel/icu

USES=		gmake gnome iconv libtool pathfix pkgconfig tar:xz vala:build
USE_GNOME=	atk cairo gdkpixbuf2 glib20 gtk30 libxml2 pango \
		introspection:build
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-pkgconfigdir=${PREFIX}/libdata/pkgconfig

INSTALL_TARGET=	install-strip

PORTSCOUT=	limitw:1,even

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=		gettext-tools
NLS_CONFIGURE_ENABLE=	nls

.include <bsd.port.mk>
