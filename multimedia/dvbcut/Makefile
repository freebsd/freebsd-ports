PORTNAME=	dvbcut
PORTVERSION=	0.7.4
DISTVERSIONPREFIX=	v
PORTREVISION=	7
CATEGORIES=	multimedia

MAINTAINER=	se@FreeBSD.org
COMMENT=	Qt application for cutting of MPEG PS and MPEG TS streams (DVB)
WWW=		https://github.com/bernhardu/dvbcut-deb/

BROKEN=		Does not build with ffmpeg > 6

LICENSE=	GPLv2

BUILD_DEPENDS=	ffmpeg:multimedia/ffmpeg \
		mplayer:multimedia/mplayer
LIB_DEPENDS=	libao.so:audio/libao \
		libavutil.so:multimedia/ffmpeg \
		libmad.so:audio/libmad
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		compiler:c++11-lang desktop-file-utils gl pkgconfig \
		qmake:outsource qt:5 shared-mime-info
USE_GITHUB=	yes
GH_ACCOUNT=	bernhardu
GH_PROJECT=	dvbcut-deb
GH_TAGNAME=	d7c8fad
USE_GL=		gl
USE_QT=		core gui widgets xml buildtools:build linguisttools:build

QMAKE_ARGS=		LRELEASE="${LRELEASE}"
QMAKE_SOURCE_PATH=	${WRKSRC}/src

CXXFLAGS+=	-I${LOCALBASE}/include \
		-I${LOCALBASE}/include/libavcodec \
		-I${LOCALBASE}/include/libavformat \
		-I${LOCALBASE}/include/libswscale \
		-D DVBCUT_VERSION=${PORTVERSION}

PORTSCOUT=	limit:^[^-]*$$

post-build:
		@${SED} -e 's;@prefix@;${PREFIX};' \
			< ${WRKSRC}/dvbcut.desktop.in \
			> ${WRKSRC}/dvbcut.desktop

do-install:
		${MKDIR} ${STAGEDIR}${PREFIX}/share/dvbcut/applications/
		${MKDIR} ${STAGEDIR}${PREFIX}/share/dvbcut/icons/
		${MKDIR} ${STAGEDIR}${PREFIX}/share/mime/packages
		${INSTALL_PROGRAM} ${WRKDIR}/.build/dvbcut ${STAGEDIR}${PREFIX}/bin/
		${INSTALL_MAN} ${WRKSRC}/dvbcut.1 ${STAGEDIR}${PREFIX}/share/man/man1/
		${INSTALL_DATA} ${WRKDIR}/.build/dvbcut*.qm ${STAGEDIR}${PREFIX}/share/dvbcut/
		${INSTALL_DATA} ${WRKSRC}/src/dvbcut*.html ${STAGEDIR}${PREFIX}/share/dvbcut/
		${INSTALL_DATA} ${WRKSRC}/dvbcut.desktop ${STAGEDIR}${PREFIX}/share/applications/
		${INSTALL_DATA} ${WRKSRC}/dvbcut.svg ${STAGEDIR}${PREFIX}/share/dvbcut/icons/
		${INSTALL_DATA} ${WRKSRC}/dvbcut.xml ${STAGEDIR}${PREFIX}/share/mime/packages/

.include <bsd.port.mk>
