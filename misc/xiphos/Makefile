PORTNAME=	xiphos
DISTVERSION=	4.3.1
PORTREVISION=	1
CATEGORIES=	misc gnome
# Don't use USE_GITHUB: the sources downloaded by USE_GITHUB cannot be
# built as they miss the file ${WRKSRC}/cmake/source_version.txt.
# See also: https://github.com/crosswire/xiphos/issues/1037
MASTER_SITES=	https://github.com/crosswire/${PORTNAME}/archive/refs/tags/${DISTVERSION}/

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Bible interface utilizing the sword framework
WWW=		https://xiphos.org

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	appstream-util:devel/appstream-glib \
		desktop-file-validate:devel/desktop-file-utils \
		itstool:textproc/itstool \
		yelp-build:textproc/yelp-tools
LIB_DEPENDS=	libbiblesync.so:misc/biblesync \
		libdbus-1.so:devel/dbus \
		libdbus-glib-1.so:devel/dbus-glib \
		libenchant.so:textproc/enchant \
		libicui18n.so:devel/icu \
		libsoup-2.4.so:devel/libsoup \
		libsword.so:misc/sword \
		libuuid.so:misc/libuuid \
		libwebkit2gtk-4.0.so:www/webkit2-gtk@40

# gettext is always needed, even if NLS is off
USES=		cmake compiler:c11 gettext gnome minizip pkgconfig
USE_GNOME=	cairo gtk30 gtkhtml4 intltool libgsf

CMAKE_OFF=	EPUB
CMAKE_ON=	GTKHTML

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	NLS

.include <bsd.port.mk>
