# New ports collection makefile for:	manslide
# Date created:		Mer 28 Feb 2007 23:25:17 CET
# Whom:                	Diego Depaoli <trebestie@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	manslide
DISTVERSION=	1.5
DISTVERSIONSUFFIX=	rc4
CATEGORIES=	multimedia kde
MASTER_SITES=	http://csgib36.ifrance.com/Manslide/

MAINTAINER=	trebestie@gmail.com
COMMENT=	Utility to simply create your own slideshow

RUN_DEPENDS=	sox:${PORTSDIR}/audio/sox \
		mencoder:${PORTSDIR}/multimedia/mplayer \
		mplayer:${PORTSDIR}/multimedia/mplayer \
		mjpegtools>=1.8.0:${PORTSDIR}/multimedia/mjpegtools \
		ImageMagick>=6.2.9:${PORTSDIR}/graphics/ImageMagick \
		transcode:${PORTSDIR}/multimedia/transcode

USE_QT_VER=	4
QT_COMPONENTS=	corelib gui moc opengl qmake rcc uic
MANSLIDEDIR=	${PREFIX}/share/manslide

MAKE_ENV?=	QTDIR=${QT_PREFIX}
QMAKE?=		${LOCALBASE}/bin/qmake-qt4
QMAKESPEC?=	${LOCALBASE}/share/qt4/mkspecs/freebsd-g++
WRKSRC=		${WRKDIR}/Manslide-${PORTVERSION}
LANGUAGE_FILES=	_ca _en _pl _it _ru
EFFECTS=	Explode Film Fire France Gun Record Smoke Sunset

DESKTOP_ENTRIES=	"Manslide" \
  			"Create your slideshow" \
  			"" \
			"Manslide" \
       			"Application;AudioVideo;" \
			false

.if defined (WITH_XINE)
RUN_DEPENDS+=	xine:${PORTSDIR}/multimedia/xine
.endif

post-extract:
# bash it isn't the FreeBSD's default shell
	@${REINPLACE_CMD} -e 's|bash|sh|g' ${WRKSRC}/mainfrm.cpp

do-configure:
	@cd ${WRKSRC} \
	&&  ${SETENV} ${MAKE_ENV} ${QMAKE} -spec ${QMAKESPEC}

pre-install:
	${MKDIR} ${MANSLIDEDIR}/Interface/Transitions
	${INSTALL_PROGRAM} ${WRKSRC}/Manslide ${MANSLIDEDIR}/

.for effects in ${EFFECTS}
	${MKDIR} ${MANSLIDEDIR}/Effects/${effects}
	${INSTALL_DATA} ${WRKSRC}/Effects/${effects}/*jpg ${MANSLIDEDIR}/Effects/${effects}/
.endfor
	${INSTALL_DATA} ${WRKSRC}/Interface/Transitions/*png ${MANSLIDEDIR}/Interface/Transitions/
# Wrong extension
	${INSTALL_DATA} ${WRKSRC}/Interface/*PNG ${MANSLIDEDIR}/Interface/

	${INSTALL_DATA} ${WRKSRC}/Interface/*png ${MANSLIDEDIR}/Interface

.for lang in ${LANGUAGE_FILES}
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}${lang}.qm ${MANSLIDEDIR}
.endfor

	${LN} -fs ${MANSLIDEDIR}/Manslide ${PREFIX}/bin/

.include <bsd.port.mk>
