# Created by: Diego Depaoli <trebestie@gmail.com>
# $FreeBSD$

PORTNAME=	smile
PORTVERSION=	1.0
PORTREVISION=	5
CATEGORIES=	multimedia kde
MASTER_SITES=	http://download.tuxfamily.org/smiletool/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Slideshow Maker

RUN_DEPENDS=	sox>=14.0:${PORTSDIR}/audio/sox \
		mencoder:${PORTSDIR}/multimedia/mencoder \
		mplayer:${PORTSDIR}/multimedia/mplayer \
		ImageMagick>=6.4:${PORTSDIR}/graphics/ImageMagick

USES=		qmake
USE_QT4=	gui corelib rcc_build moc_build uic_build \
		opengl webkit

WRKSRC=		${WRKDIR}/${PORTNAME}

DESKTOP_ENTRIES="Smile" "${COMMENT}" "${PREFIX}/share/pixmaps/smile.png" \
		"${PORTNAME}" "AudioVideo;Qt;" true

post-patch:
	@${REINPLACE_CMD} -e 's|bash|sh|' ${WRKSRC}/mainfrm.cpp \
		${WRKSRC}/render.cpp
	@${RM} -f ${WRKSRC}/ui_*.h ${WRKSRC}/moc_*.cpp ${WRKSRC}/qrc_*.cpp \
		${WRKSRC}/BIB_ManSlide/Help/doc_fr ${WRKSRC}/BIB_ManSlide/*/*~

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} "BIB_ManSlide Interface" ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/*.qm ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/Interface/Theme/smile.png \
		${STAGEDIR}${PREFIX}/share/pixmaps
	${INSTALL_PROGRAM} ${WRKSRC}/smile ${STAGEDIR}${DATADIR}
	${LN} -fs ${DATADIR}/smile ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
