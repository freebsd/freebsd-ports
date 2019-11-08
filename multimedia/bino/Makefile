# Created by: Mykola Dzham <i@levsha.me>
# $FreeBSD$

PORTNAME=	bino
PORTVERSION=	1.6.5
PORTREVISION=	5
CATEGORIES=	multimedia
MASTER_SITES=	https://download.savannah.nongnu.org/releases/bino/

MAINTAINER=	i@levsha.me
COMMENT=	3D video player with multi-display support

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libass.so:multimedia/libass \
		libavformat.so:multimedia/ffmpeg \
		libopenal.so:audio/openal-soft

USES=		autoreconf compiler:c++11-lang desktop-file-utils gl gmake \
		gnome iconv pkgconfig qt:5 tar:xz
USE_GL=		gl glu glew
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
USE_QT=		buildtools_build core gui opengl widgets
USE_CXXSTD=	c++11

# no port fow equalizer now, lirc detecting not working
CONFIGURE_ARGS=	--without-equalizer --without-lirc --docdir=${DOCSDIR}

EXTRA_PATCHES= ${FILESDIR}/glew-fix-7098cd6a.patch

INFO=		bino

OPTIONS_DEFINE=	NLS DOCS
OPTIONS_SUB=	yes

NLS_USES=	gettext
NLS_CONFIGURE_ENABLE=nls

.include <bsd.port.mk>
