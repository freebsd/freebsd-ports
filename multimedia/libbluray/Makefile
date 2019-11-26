# Created by: kamikaze@bsdforen.de
# $FreeBSD$

PORTNAME=	libbluray
DISTVERSION=	1.1.1
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	multimedia
MASTER_SITES=	ftp://ftp.videolan.org/pub/videolan/${PORTNAME}/${PORTVERSION}/ \
		http://blu.opsec.eu/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Blu-Ray discs playback library for media players

LICENSE=	LGPL21

LIB_DEPENDS=	libfreetype.so:print/freetype2 \
		libfontconfig.so:x11-fonts/fontconfig
# dlopen dependencies
LIB_DEPENDS+=	libaacs.so:multimedia/libaacs \
		libbdplus.so:multimedia/libbdplus

USES=		gnome iconv libtool pathfix pkgconfig tar:bzip2
USE_GNOME=	libxml2
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes

CONFIGURE_ARGS=	--disable-static
CONFIGURE_ENV=	PACKAGES="" # Bug #226009

INSTALL_TARGET=	install-strip

.include "Makefile.include"

OPTIONS_DEFINE=	JAVA
OPTIONS_SUB=	yes

JAVA_DESC=	Enable Blu-Ray Java support

JAVA_BUILD_DEPENDS=		ant:devel/apache-ant
JAVA_CATEGORIES=		java
JAVA_CONFIGURE_ENABLE=		bdjava-jar
JAVA_CONFIGURE_ENV=		JDK_HOME="${JAVA_HOME}"
JAVA_USE=			JAVA=yes
JAVA_VARS=			JAVA_BUILD=yes JAVA_RUN=yes

post-patch:
	@${RLN} ${WRKSRC}/jni/linux ${WRKSRC}/jni/freebsd

.include <bsd.port.mk>
