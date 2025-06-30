PORTNAME=	libbluray
DISTVERSION=	1.3.4
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	multimedia
MASTER_SITES=	https://get.videolan.org/${PORTNAME}/${DISTVERSION}/ \
		https://download.videolan.org/pub/videolan/${PORTNAME}/${DISTVERSION}/

MAINTAINER=	se@FreeBSD.org
COMMENT=	Blu-Ray discs playback library for media players
WWW=		https://www.videolan.org/developers/libbluray.html

LICENSE=	LGPL21

LIB_DEPENDS=	libfreetype.so:print/freetype2 \
		libfontconfig.so:x11-fonts/fontconfig

USES=		cpe gnome libtool pathfix pkgconfig tar:bzip2
CPE_VENDOR=	videolan
USE_GNOME=	libxml2
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes

CONFIGURE_ARGS=	--disable-doxygen-doc --disable-optimizations --disable-static
CONFIGURE_ENV=	PACKAGES="" # Bug #226009

INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	JAVA
OPTIONS_SUB=	yes

JAVA_DESC=	Enable Blu-Ray Java support

JAVA_CATEGORIES=		java
JAVA_BUILD_DEPENDS=		ant:devel/apache-ant
JAVA_USES=		java:build
JAVA_CONFIGURE_ENABLE=		bdjava-jar
JAVA_CONFIGURE_WITH=		java9
JAVA_MAKE_ENV=	JAVA_HOME=${JAVA_HOME} \
		PATH=${JAVA_HOME}/bin:${PATH}
JAVA_VARS=	JAVA_VERSION=8

pre-build:
	@${REINPLACE_CMD} -e 's|/usr/share|${LOCALBASE}/share|' ${WRKSRC}/src/libbluray/bdj/bdj.c

.include <bsd.port.mk>
