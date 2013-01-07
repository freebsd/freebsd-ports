# Created by: Diego Depaoli <trebestie@gmail.com>
# $FreeBSD$

PORTNAME=	smile
PORTVERSION=	1.0
PORTREVISION=	4
CATEGORIES=	multimedia kde
MASTER_SITES=	http://download.tuxfamily.org/smiletool/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Slideshow Maker

RUN_DEPENDS=	sox>=14.0:${PORTSDIR}/audio/sox \
		mencoder:${PORTSDIR}/multimedia/mencoder \
		mplayer:${PORTSDIR}/multimedia/mplayer \
		ImageMagick>=6.4:${PORTSDIR}/graphics/ImageMagick

USE_QT4=	qmake_build gui corelib rcc_build moc_build uic_build \
		opengl webkit

MAKE_ENV=	QTDIR=${QT_PREFIX}
WRKSRC=		${WRKDIR}/${PORTNAME}
MAKE_JOBS_SAFE=	yes

DESKTOP_ENTRIES="Smile" "${COMMENT}" "${PREFIX}/share/pixmaps/smile.png" \
		"${PORTNAME}" "AudioVideo;Qt;" false

post-patch:
	@${REINPLACE_CMD} -e 's|bash|sh|' ${WRKSRC}/mainfrm.cpp \
		${WRKSRC}/render.cpp
	@${RM} -f ${WRKSRC}/ui_*.h ${WRKSRC}/moc_*.cpp ${WRKSRC}/qrc_*.cpp \
		${WRKSRC}/BIB_ManSlide/Help/doc_fr ${WRKSRC}/BIB_ManSlide/*/*~

do-configure:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		${QMAKE} -spec ${QMAKESPEC} smile.pro

do-install:
	@${MKDIR} ${DATADIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} "BIB_ManSlide Interface" ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/*.qm ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/Interface/Theme/smile.png \
		${PREFIX}/share/pixmaps
	${INSTALL_PROGRAM} ${WRKSRC}/smile ${DATADIR}
	${LN} -fs ${DATADIR}/smile ${PREFIX}/bin

.include <bsd.port.mk>
