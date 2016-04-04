# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=	gspell
PORTVERSION=	0.1.2
CATEGORIES=	textproc
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	olivierd@FreeBSD.org
COMMENT=	Spell checking for GTK+

LICENSE=	GPLv2

BUILD_DEPENDS=	valac:lang/vala \
	iso-codes>=3.57:misc/iso-codes
LIB_DEPENDS=	libenchant.so:textproc/enchant

PORTSCOUT=	limit:^0\.1\.

USES=	gmake iconv libtool pathfix pkgconfig tar:xz
USE_GNOME=	glib20 gtksourceview3 introspection:build libxml2
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

CONFIGURE_ARGS=--enable-introspection=yes \
	--enable-compile-warnings=no \
	--without-html-dir \
	--with-pkgconfigdir=${PREFIX}/libdata/pkgconfig

OPTIONS_DEFINE=	NLS
NLS_USES=	gettext-tools
NLS_CONFIGURE_ENABLE=	nls
OPTIONS_SUB=	yes

.include <bsd.port.mk>
