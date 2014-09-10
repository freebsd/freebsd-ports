# Created by: Mykola Dzham <i@levsha.me>
# $FreeBSD$

PORTNAME=	bino
PORTVERSION=	1.4.2
PORTREVISION=	2
CATEGORIES=	multimedia
MASTER_SITES=	http://download.savannah.nongnu.org/releases/bino/ http://levsha.me/ports/distfiles/

MAINTAINER=	i@levsha.me
COMMENT=	3D video player with multi-display support

LICENSE=	GPLv3

USES=		gmake pkgconfig tar:xz
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
USE_QT4=	moc_build opengl rcc_build

# no port fow equalizer now, lirc detecting not working
CONFIGURE_ARGS+=	--without-equalizer --without-liblircclient --docdir=${DOCSDIR}

LIB_DEPENDS+=	libass.so:${PORTSDIR}/multimedia/libass \
		libavformat.so:${PORTSDIR}/multimedia/ffmpeg \
		libGLEW.so:${PORTSDIR}/graphics/glew \
		libopenal.so:${PORTSDIR}/audio/openal-soft

INFO=	bino

OPTIONS_DEFINE=	NLS DOCS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

# fixes build on non UTF-8 enviroments
post-patch:
	@${REINPLACE_CMD} -e 's|echo $<|LANG=C; LC_ALL=C; &|' \
		${WRKSRC}/src/Makefile.in

.include <bsd.port.mk>
