# New ports collection makefile for:	mediadownloader
# Date created:		2010-07-24
# Whom:			Gvozdikov Veniamin <g.veniamin@googlemail.com>
#
# $FreeBSD$
#

PORTNAME=	mediadownloader
PORTVERSION=	1.5.2
PORTREVISION=	1
CATEGORIES=	multimedia www
MASTER_SITES=	SF/googleimagedown/project/${PORTVERSION}/
DISTNAME=	${PORTNAME}_${PORTVERSION}-src

MAINTAINER=	g.veniamin@googlemail.com
COMMENT=	Search, watch, and download from Google Image and YouTube

LICENSE=	GPLv3

USE_GL=		gl glu
USE_XORG=	xtst
USE_GSTREAMER=	ffmpeg
USE_QT4=	dbus gui network moc_build opengl phonon phonon-gst \
		qmake_build rcc_build uic_build webkit xml xmlpatterns
QMAKEPRO=	${PORTNAME}.pro
PLIST_FILES=	bin/${PORTNAME}

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

DESKTOP_ENTRIES="MediaDownloader" "${COMMENT}" \
		"${DATADIR}/${PORTNAME}.png" "${PORTNAME}" \
		"" false

do-configure:
	@${REINPLACE_CMD} -e 's|/usr|${PREFIX}|g' \
		${WRKSRC}/${QMAKEPRO}
	@cd ${WRKSRC} && ${QMAKE} ${QMAKEFLAGS} ${QMAKEPRO}

.include <bsd.port.mk>
