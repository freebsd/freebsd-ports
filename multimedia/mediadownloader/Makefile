# Created by: Gvozdikov Veniamin <g.veniamin@googlemail.com>
# $FreeBSD$

PORTNAME=	mediadownloader
PORTVERSION=	1.5.2
PORTREVISION=	6
CATEGORIES=	multimedia www
MASTER_SITES=	SF/googleimagedown/project/${PORTVERSION}/
DISTNAME=	${PORTNAME}_${PORTVERSION}-src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Search, watch, and download from Google Image and YouTube

LICENSE=	GPLv3

DEPRECATED=		Qt4 has been EOL since december 2015
EXPIRATION_DATE=	2019-03-15

USES=		qmake qt:4
USE_GL=		gl glu
USE_XORG=	xtst
USE_GSTREAMER=	ffmpeg
USE_QT=		dbus gui network moc_build opengl phonon phonon-gst \
		rcc_build uic_build webkit xml xmlpatterns
QMAKEPRO=	${PORTNAME}.pro
PLIST_FILES=	bin/${PORTNAME}

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

DESKTOP_ENTRIES="MediaDownloader" "${COMMENT}" \
		"${DATADIR}/${PORTNAME}.png" "${PORTNAME}" \
		"" true

pre-configure:
	@${REINPLACE_CMD} -e 's|/usr|${PREFIX}|g' \
		${WRKSRC}/${QMAKEPRO}

.include <bsd.port.mk>
