# Created by: se@FreeBSD.org
# $FreeBSD$

PORTNAME=	dvbcut
PORTVERSION=	0.7.3
DISTVERSIONPREFIX=	v
PORTREVISION=	2
CATEGORIES=	multimedia

MAINTAINER=	se@FreeBSD.org
COMMENT=	Qt application for cutting of MPEG PS and MPEG TS streams (DVB)

LICENSE=	GPLv2

BUILD_DEPENDS=	mplayer:multimedia/mplayer \
		ffmpeg:multimedia/ffmpeg
LIB_DEPENDS=	liba52.so:audio/liba52 \
		libao.so:audio/libao \
		libmad.so:audio/libmad \
		libavutil.so:multimedia/ffmpeg
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		compiler:c++11-lang desktop-file-utils pkgconfig \
		qmake:outsource shared-mime-info

USE_GITHUB=	yes
GH_ACCOUNT=	bernhardu
GH_PROJECT=	dvbcut-deb

CXXFLAGS+=	-I${LOCALBASE}/include \
		-I${LOCALBASE}/include/libavcodec \
		-I${LOCALBASE}/include/libavformat \
		-I${LOCALBASE}/include/libswscale \
		-D DVBCUT_VERSION=${PORTVERSION}

QMAKE_SOURCE_PATH=${WRKSRC}/src
QMAKE_ARGS=	LRELEASE="${LRELEASE}"

OPTIONS_RADIO=	QT
OPTIONS_RADIO_QT=	QT4 QT5
OPTIONS_DEFAULT=	QT5

QT4_USES=	qt:4
QT4_USE=	QT=corelib,gui,xml,qt3support,linguisttools_build,moc_build,rcc_build,uic_build
QT5_USES=	qt:5
QT5_USE=	QT=core,gui,widgets,xml,buildtools_build,linguisttools_build GL=gl

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MQT4}
DEPRECATED=		Qt4 has been EOL since december 2015
EXPIRATION_DATE=	2019-03-15
.endif

post-build:
		@${SED} -e 's;@prefix@;${PREFIX};' \
			< ${WRKSRC}/dvbcut.desktop.in \
			> ${WRKSRC}/dvbcut.desktop

do-install:
		${INSTALL_PROGRAM} ${WRKDIR}/.build/dvbcut ${STAGEDIR}${PREFIX}/bin/
		${INSTALL_MAN} ${WRKSRC}/dvbcut.1 ${STAGEDIR}${MANPREFIX}/man/man1/
		${MKDIR} ${STAGEDIR}${PREFIX}/share/applications
		${INSTALL_DATA} ${WRKSRC}/dvbcut.desktop ${STAGEDIR}${PREFIX}/share/applications/
		${MKDIR} ${STAGEDIR}${PREFIX}/share/dvbcut/icons/
		${INSTALL_DATA} ${WRKSRC}/dvbcut.svg ${STAGEDIR}${PREFIX}/share/dvbcut/icons/
		${INSTALL_DATA} ${WRKSRC}/icons/* ${STAGEDIR}${PREFIX}/share/dvbcut/icons/
		${MKDIR} ${STAGEDIR}${PREFIX}/share/mime/packages
		${INSTALL_DATA} ${WRKSRC}/dvbcut.xml ${STAGEDIR}${PREFIX}/share/mime/packages/

.include <bsd.port.mk>
