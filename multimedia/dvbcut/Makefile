# Created by: se@FreeBSD.org
# $FreeBSD$

PORTNAME=	dvbcut
PORTVERSION=	0.7.2
PORTREVISION=	1
CATEGORIES=	multimedia

MAINTAINER=	se@FreeBSD.org
COMMENT=	Qt application for cutting of MPEG PS and MPEG TS streams (DVB)

LICENSE=	GPLv2

BROKEN=		fails to build with ffmpeg 4.0

BUILD_DEPENDS=	mplayer:multimedia/mplayer \
		ffmpeg:multimedia/ffmpeg
LIB_DEPENDS=	liba52.so:audio/liba52 \
		libao.so:audio/libao \
		libmad.so:audio/libmad \
		libavutil.so:multimedia/ffmpeg
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_GITHUB=	yes
GH_ACCOUNT=	bernhardu
GH_PROJECT=	dvbcut-deb
GH_TAGNAME=	040c1ef

USES=		qmake:outsource pkgconfig desktop-file-utils shared-mime-info

CXXFLAGS+=	-I${LOCALBASE}/include \
		-I${LOCALBASE}/include/libavcodec \
		-I${LOCALBASE}/include/libavformat \
		-I${LOCALBASE}/include/libswscale \
		-D DVBCUT_VERSION=$(PORTVERSION)

QMAKE_SOURCE_PATH=${WRKSRC}/src
QMAKE_ARGS=	LRELEASE="${LRELEASE}"

OPTIONS_RADIO=	QT
OPTIONS_RADIO_QT=	QT4 QT5
OPTIONS_DEFAULT=	QT4

QT4_USE=	QT4=corelib,gui,xml,qt3support,linguisttools_build,moc_build,rcc_build,uic_build
QT5_USE=	QT5=core,gui,widgets,xml,buildtools_build,linguisttools_build GL=gl

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
