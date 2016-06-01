# Created by: kamikaze@bsdforen.de
# $FreeBSD$

PORTNAME=	libbluray
PORTVERSION=	0.9.3
PORTEPOCH=	1
CATEGORIES=	multimedia
MASTER_SITES=	ftp://ftp.videolan.org/pub/videolan/${PORTNAME}/${PORTVERSION}/ \
		http://blu.opsec.eu/

MAINTAINER=	kami@FreeBSD.org
COMMENT=	Blu-Ray discs playback library for media players

LICENSE=	LGPL21

LIB_DEPENDS=	libfreetype.so:print/freetype2 \
		libfontconfig.so:x11-fonts/fontconfig
# dlopen dependencies
LIB_DEPENDS+=	libaacs.so:multimedia/libaacs \
		libbdplus.so:multimedia/libbdplus

INSTALL_TARGET=	install-strip
USES=		autoreconf iconv libtool pathfix pkgconfig tar:bzip2
USE_LDCONFIG=	yes
USE_GNOME=	libxml2
GNU_CONFIGURE=	yes

.include "Makefile.include"

OPTIONS_DEFINE=	JAVA
OPTIONS_SUB=	yes
JAVA_DESC=	Enable Blu-Ray Java support

JAVA_BUILD_DEPENDS=		ant:devel/apache-ant
JAVA_CATEGORIES=		java
JAVA_USE=			JAVA=yes
JAVA_VARS=			JAVA_VERSION=1.6+ JAVA_BUILD=yes JAVA_RUN=yes
JAVA_CONFIGURE_ENABLE=		bdjava
JAVA_CONFIGURE_ENV=		JDK_HOME="${JAVA_HOME}"

.include <bsd.port.mk>
