# Created by: se@FreeBSD.org
# $FreeBSD$

PORTNAME=	dvbcut
PORTVERSION=	0.6.2.a1
PORTREVISION=	4
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

USE_GITHUB=	yes
GH_ACCOUNT=	nextghost
GH_PROJECT=	dvbcut-qt4
GH_TAGNAME=	81c31ed

USES=		desktop-file-utils pkgconfig qmake shared-mime-info
USE_QT4=	corelib gui xml linguisttools_build moc_build rcc_build \
		uic_build

CXXFLAGS+=	-I${LOCALBASE}/include \
		-I${LOCALBASE}/include/libavcodec \
		-I${LOCALBASE}/include/libavformat \
		-I${LOCALBASE}/include/libswscale

post-configure:
		@${REINPLACE_CMD} -e '/CXX.*moc_progress/s/ -o / -O0 -o /' ${WRKSRC}/src/Makefile

post-build:
		@${SED} -e 's;@prefix@;${PREFIX};' \
			< ${WRKSRC}/dvbcut.desktop.in \
			> ${WRKSRC}/dvbcut.desktop

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/bin/dvbcut ${STAGEDIR}${PREFIX}/bin/
		${INSTALL_MAN} ${WRKSRC}/dvbcut.1 ${STAGEDIR}${MANPREFIX}/man/man1/
		${MKDIR} ${STAGEDIR}${PREFIX}/share/applications
		${INSTALL_DATA} ${WRKSRC}/dvbcut.desktop ${STAGEDIR}${PREFIX}/share/applications/
		${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/dvbcut
		${INSTALL_DATA} ${WRKSRC}/dvbcut.svg ${STAGEDIR}${PREFIX}/share/icons/dvbcut/
		${INSTALL_DATA} ${WRKSRC}/icons/* ${STAGEDIR}${PREFIX}/share/icons/dvbcut/
		${MKDIR} ${STAGEDIR}${PREFIX}/share/mime/packages
		${INSTALL_DATA} ${WRKSRC}/dvbcut.xml ${STAGEDIR}${PREFIX}/share/mime/packages/

.include <bsd.port.mk>
