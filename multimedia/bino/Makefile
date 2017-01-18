# Created by: Mykola Dzham <i@levsha.me>
# $FreeBSD$

PORTNAME=	bino
PORTVERSION=	1.4.2
PORTREVISION=	6
CATEGORIES=	multimedia
MASTER_SITES=	http://download.savannah.nongnu.org/releases/bino/ http://levsha.me/ports/distfiles/

MAINTAINER=	i@levsha.me
COMMENT=	3D video player with multi-display support

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libass.so:multimedia/libass \
		libavformat.so:multimedia/ffmpeg \
		libopenal.so:audio/openal-soft

USES=		desktop-file-utils gmake pkgconfig tar:xz
USE_GL=		glew
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
USE_QT4=	moc_build opengl rcc_build

# no port fow equalizer now, lirc detecting not working
CONFIGURE_ARGS=	--without-equalizer --without-liblircclient --docdir=${DOCSDIR}

INFO=		bino

OPTIONS_DEFINE=	NLS DOCS
OPTIONS_SUB=	yes

NLS_USES=	gettext
NLS_CONFIGURE_ENABLE=nls

.include <bsd.port.mk>
