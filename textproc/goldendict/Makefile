# Created by: Boris Samorodov <bsam@FreeBSD.org>
# $FreeBSD$

PORTNAME=	goldendict
DISTVERSION=	1.5.0-g20210115
CATEGORIES=	textproc

MAINTAINER=	bsam@FreeBSD.org
COMMENT=	Feature-rich dictionary lookup program

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libhunspell-1.7.so:textproc/hunspell \
		liblzo2.so:archivers/lzo2 \
		libogg.so:audio/libogg \
		libtiff.so:graphics/tiff \
		libvorbis.so:audio/libvorbis \
		libzstd.so:archivers/zstd

USES=		compiler:c++11-lang gnome iconv:wchar_t pkgconfig \
		qmake qt:5 xorg
USE_GITHUB=	yes
GH_TAGNAME=	73ec1b5
USE_XORG=	x11 xtst
USE_QT=		buildtools_build linguisttools_build core gui help \
		network printsupport sql svg webkit widgets \
		x11extras xml
INSTALLS_ICONS=	yes
QMAKE_ARGS=	${PORTNAME}.pro CONFIG+="zim_support"

OPTIONS_DEFINE=	EPWING FFMPEG MULTIMEDIA OPENCC
OPTIONS_DEFAULT=	EPWING FFMPEG MULTIMEDIA OPENCC

EPWING_DESC=		Japanese EPWING dictionary format support
EPWING_LIB_DEPENDS=	libeb.so:japanese/eb
EPWING_QMAKE_OFF=	CONFIG+="no_epwing_support"

FFMPEG_LIB_DEPENDS=	libao.so:audio/libao \
			libavutil.so:multimedia/ffmpeg
FFMPEG_QMAKE_OFF=	CONFIG+="no_ffmpeg_player"

MULTIMEDIA_DESC=	Multimedia support with QMediaPlayer
MULTIMEDIA_USE=		QT=multimedia
MULTIMEDIA_QMAKE_OFF=	CONFIG+="no_qtmultimedia_player"

OPENCC_DESC=		Chinese conversion support via OpenCC
OPENCC_LIB_DEPENDS=	libopencc.so:chinese/opencc
OPENCC_QMAKE_ON=	CONFIG+="chinese_conversion_support"

post-patch:
	@${REINPLACE_CMD} -e '/^VERSION = /s,git,&${GH_TAGNAME},' \
		${WRKSRC}/goldendict.pro

post-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}/locale
	${INSTALL_DATA} ${WRKSRC}/locale/*.qm ${STAGEDIR}${DATADIR}/locale
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

post-stage:
	${RM} ${STAGEDIR}${PREFIX}/share/applications/ecp.*

.include <bsd.port.mk>
