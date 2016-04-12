# Created by: Mykola Dzham <i@levsha.me>
# $FreeBSD$

PORTNAME=	bino
PORTVERSION=	1.4.2
PORTREVISION=	3
CATEGORIES=	multimedia
MASTER_SITES=	http://download.savannah.nongnu.org/releases/bino/ http://levsha.me/ports/distfiles/

MAINTAINER=	i@levsha.me
COMMENT=	3D video player with multi-display support

LICENSE=	GPLv3+

USES=		desktop-file-utils gmake pkgconfig tar:xz
USE_GL=		glew
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
USE_QT4=	moc_build opengl rcc_build

# no port fow equalizer now, lirc detecting not working
CONFIGURE_ARGS+=	--without-equalizer --without-liblircclient --docdir=${DOCSDIR}

LIB_DEPENDS+=	libass.so:multimedia/libass \
		libavformat.so:multimedia/ffmpeg \
		libopenal.so:audio/openal-soft

INFO=	bino

OPTIONS_DEFINE=	NLS DOCS
OPTIONS_SUB=	yes

NLS_USES=	gettext
NLS_CONFIGURE_ENABLE=nls

# fixes build on non UTF-8 enviroments
post-patch:
	@${REINPLACE_CMD} -e 's|echo $<|LANG=C; LC_ALL=C; &|' \
		${WRKSRC}/src/Makefile.in

.include <bsd.port.mk>
