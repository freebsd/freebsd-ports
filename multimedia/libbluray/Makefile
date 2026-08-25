PORTNAME=	libbluray
DISTVERSION=	1.5.0
PORTEPOCH=	1
CATEGORIES=	multimedia
MASTER_SITES=	https://get.videolan.org/${PORTNAME}/${DISTVERSION}/ \
		https://download.videolan.org/pub/videolan/${PORTNAME}/${DISTVERSION}/

MAINTAINER=	se@FreeBSD.org
COMMENT=	Blu-Ray discs playback library for media players
WWW=		https://www.videolan.org/developers/libbluray.html

LICENSE=	LGPL21

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libudfread.so:multimedia/libudfread

USES=		cpe gnome meson pkgconfig tar:xz
CPE_VENDOR=	videolan
USE_GNOME=	libxml2
JAVA_VERSION=	11+
USE_LDCONFIG=	yes

MESON_ARGS=	-Ddefault_library=shared \
		-Dembed_udfread=false

OPTIONS_DEFINE=	JAVA
OPTIONS_SUB=	yes

JAVA_DESC=	Enable Blu-Ray Java support

JAVA_CATEGORIES=	java
JAVA_BUILD_DEPENDS=	ant:devel/apache-ant
JAVA_USES=		java:build

JAVA_MESON_ENABLED=	bdj_jar

.include <bsd.port.mk>
