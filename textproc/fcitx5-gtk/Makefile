PORTNAME=	fcitx5-gtk
DISTVERSION=	5.0.23
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	https://download.fcitx-im.org/fcitx5/${PORTNAME}/

MAINTAINER=	khng@FreeBSD.org
COMMENT?=	Fcitx support for GTK ${FLAVOR}
WWW=		https://github.com/fcitx/fcitx5-gtk

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/LICENSES/LGPL-2.1-or-later.txt

LIB_DEPENDS=	libxkbcommon.so:x11/libxkbcommon
RUN_DEPENDS?=	fcitx5-gtk-common>=${DISTVERSION}:textproc/fcitx5-gtk-common

FLAVORS?=	gtk3 gtk2 gtk4
FLAVOR?=	${FLAVORS:[1]}

gtk2_PKGNAMESUFFIX=	2
gtk3_PKGNAMESUFFIX=	3
gtk4_PKGNAMESUFFIX=	4

USES=		cmake compiler:c++17-lang gettext-tools gnome kde:5 pkgconfig \
		tar:xz xorg

USE_GNOME=	cairo gdkpixbuf2 glib20 introspection
USE_KDE=	ecm
USE_LDCONFIG=	yes
USE_XORG=	x11

CMAKE_ON?=	BUILD_ONLY_PLUGIN

.if ${FLAVOR} == gtk3
CMAKE_OFF+=	ENABLE_GTK2_IM_MODULE ENABLE_GTK4_IM_MODULE
USE_GNOME+=	gtk30
.elif ${FLAVOR} == gtk2
CMAKE_OFF+=	ENABLE_GTK3_IM_MODULE ENABLE_GTK4_IM_MODULE
USE_GNOME+=	gtk20
.elif ${FLAVOR} == gtk4
CMAKE_OFF+=	ENABLE_GTK2_IM_MODULE ENABLE_GTK3_IM_MODULE
USE_GNOME+=	gtk40
.endif

PLIST?=		${PKGDIR}/pkg-plist.${FLAVOR}
PLIST_SUB=	VER=${PORTVERSION}

PLIST_SUB=	VER=${PORTVERSION}

.include <bsd.port.mk>
