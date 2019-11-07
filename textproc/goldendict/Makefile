# Created by: Boris Samorodov <bsam@FreeBSD.org>
# $FreeBSD$

PORTNAME=	goldendict
DISTVERSION=	1.5.0-g20190709
PORTREVISION=	2
CATEGORIES=	textproc

MAINTAINER=	bsam@FreeBSD.org
COMMENT=	Feature-rich dictionary lookup program

LICENSE=	GPLv3

LIB_DEPENDS=	libhunspell-1.7.so:textproc/hunspell \
		liblzo2.so:archivers/lzo2 \
		libvorbis.so:audio/libvorbis

USES=		compiler:c++11-lang gnome iconv:wchar_t pkgconfig \
		qmake qt:5 xorg
USE_GITHUB=	yes
GH_TAGNAME=	05bfc35
USE_XORG=	xtst
USE_QT=		buildtools_build linguisttools_build core gui help \
		multimedia network printsupport sql svg webkit widgets \
		x11extras xml
INSTALLS_ICONS=	yes
QMAKE_ARGS=	${PORTNAME}.pro CONFIG+="zim_support"

OPTIONS_DEFINE=	EPWING FFMPEG OPENCC
OPTIONS_DEFAULT=	EPWING FFMPEG OPENCC

EPWING_DESC=		Japanese EPWING dictionary format support
EPWING_LIB_DEPENDS=	libeb.so:japanese/eb
EPWING_QMAKE_OFF=	CONFIG+="no_epwing_support"

FFMPEG_LIB_DEPENDS=	libao.so:audio/libao \
			libavutil.so:multimedia/ffmpeg
FFMPEG_QMAKE_OFF=	CONFIG+="no_ffmpeg_player"

OPENCC_DESC=		Chinese conversion support via OpenCC
OPENCC_LIB_DEPENDS=	libopencc.so:chinese/opencc
OPENCC_QMAKE_ON=	CONFIG+="chinese_conversion_support"

post-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}/locale
	${INSTALL_DATA} ${WRKSRC}/locale/*.qm ${STAGEDIR}${DATADIR}/locale
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
