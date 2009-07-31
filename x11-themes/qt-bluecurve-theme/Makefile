# New ports collection makefile for:    bluecurve-unified
# Date created:         3 October 2002
# Whom:                 Eugeney Ryzhyk
#
# $FreeBSD$
#

PORTNAME=	qt-bluecurve-theme
PORTREVISION=	4
COMMENT=	The Bluecurve QT theme

MASTERDIR=	${.CURDIR}/../bluecurve-themes

USE_QT_VER=	3
BUILD_WRKSRC=	${WRKSRC}/art/qt/Bluecurve

QT_CFLAGS=	-I${LOCALBASE}/include -DQT_THREAD_SUPPORT ${PTHREAD_CFLAGS}
QT_LIBS=	-L${LOCALBASE}/lib -lqt-mt ${PTHREAD_LIBS}

SUB_FILES=	pkg-message

post-patch:
	@${REINPLACE_CMD} -e 's|GtkStyle|0|' ${BUILD_WRKSRC}/bluecurve.cpp
	@${REINPLACE_CMD} -e \
		's|^\(libraryPath\)=.*|\1=${LOCALBASE}/lib/plugins|' \
		${WRKSRC}/art/qt/qtrc

do-build:
	cd ${BUILD_WRKSRC} && \
	${MOC} -o bluecurve.moc bluecurve.h && \
	${CXX} ${CXXFLAGS} -Wl,-export-dynamic -shared -fPIC \
		${QT_CFLAGS} ${QT_LIBS} -o bluecurve.so \
			bluecurve.cpp plugin.cpp

do-install:
	${MKDIR} ${PREFIX}/lib/plugins/styles
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/bluecurve.so ${PREFIX}/lib/plugins/styles
	${MKDIR} ${PREFIX}/etc/settings
	${INSTALL_DATA} ${WRKSRC}/art/qt/qtrc ${PREFIX}/etc/settings/qtrc.bluecurve

post-install:
	[ -f ${PREFIX}/etc/settings/qtrc ] || \
		${INSTALL_DATA} ${WRKSRC}/art/qt/qtrc ${PREFIX}/etc/settings
	@${CAT} ${PKGMESSAGE}

.include "${MASTERDIR}/Makefile"
