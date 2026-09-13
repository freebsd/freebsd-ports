PORTNAME=	libbluray
PORTVERSION=	1.5.1
PORTEPOCH=	1
CATEGORIES=	multimedia

MAINTAINER=	se@FreeBSD.org
COMMENT=	Blu-Ray discs playback library for media players
WWW=		https://www.videolan.org/developers/libbluray.html

LICENSE=	LGPL21

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libudfread.so:multimedia/libudfread

USES=		cpe gnome meson pkgconfig
CPE_VENDOR=	videolan
USE_GITLAB=	yes
GL_SITE=	https://code.videolan.org
GL_ACCOUNT=	videolan
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
