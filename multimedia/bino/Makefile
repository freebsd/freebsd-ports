# Created by: Mykola Dzham <i@levsha.me>
# $FreeBSD$

PORTNAME=	bino
PORTVERSION=	1.6.5
PORTREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	https://download.savannah.nongnu.org/releases/bino/

MAINTAINER=	i@levsha.me
COMMENT=	3D video player with multi-display support

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN=		fails to build with ffmpeg 4.0

LIB_DEPENDS=	libass.so:multimedia/libass \
		libavformat.so:multimedia/ffmpeg \
		libopenal.so:audio/openal-soft

USES=		autoreconf desktop-file-utils gmake iconv pkgconfig tar:xz
USE_GL=		gl glu glew
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
USE_QT5=	buildtools_build core gui opengl widgets
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
