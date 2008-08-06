# New ports collection makefile for: smile
# Date created:		Mer 06 Jul 2008 23:44:00 CET
# Whom:                	Diego Depaoli <trebestie@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	smile
PORTVERSION=	0.6.1
CATEGORIES=	multimedia kde
MASTER_SITES=	http://download.tuxfamily.org/smiletool/

MAINTAINER=	trebestie@gmail.com
COMMENT=	Slideshow Maker in Linux Environment

RUN_DEPENDS=	sox>=14.0:${PORTSDIR}/audio/sox \
		mencoder:${PORTSDIR}/multimedia/mencoder \
		mplayer:${PORTSDIR}/multimedia/mplayer \
		ImageMagick>=6.4:${PORTSDIR}/graphics/ImageMagick

USE_QT_VER=	4
QT_COMPONENTS=	qmake_build gui corelib rcc_build moc_build uic_build \
		opengl webkit

MAKE_ENV+=	QTDIR=${QT_PREFIX}
WRKSRC=		${WRKDIR}/${PORTNAME}

DESKTOP_ENTRIES="Smile" \
		"Slideshow Maker in Linux environment" \
		"smile.png" \
		"smile" \
		"Application;AudioVideo;" \
		false

post-patch:
	@${REINPLACE_CMD} -e 's|bash|sh|g' ${WRKSRC}/mainfrm.cpp \
		${WRKSRC}/render.cpp
	@${RM} -f ${WRKSRC}/ui_*.h ${WRKSRC}/moc_*.cpp ${WRKSRC}/qrc_*.cpp

do-configure:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${QMAKE} -spec ${QMAKESPEC} smile.pro

do-install:
	${MKDIR} ${DATADIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} "BIB_ManSlide Interface" ${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/*.qm ${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/Interface/Theme/smile.png ${PREFIX}/share/pixmaps/smile.png
	${INSTALL_PROGRAM} ${WRKSRC}/smile ${DATADIR}/
	${LN} -fs ${DATADIR}/smile ${PREFIX}/bin/

.include <bsd.port.mk>
