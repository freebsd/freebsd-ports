# Created by: se@FreeBSD.org
# $FreeBSD$

PORTNAME=	dvbcut
PORTVERSION=	0.6.1
PORTREVISION=	2
CATEGORIES=	multimedia
MASTER_SITES=	http://www.mr511.de/dvbcut/

MAINTAINER=	se@FreeBSD.org
COMMENT=	Qt application for cutting of MPEG PS and MPEG TS streams (DVB)

LICENSE=	GPLv2

BUILD_DEPENDS=	mplayer:${PORTSDIR}/multimedia/mplayer
LIB_DEPENDS=	a52:${PORTSDIR}/audio/liba52 \
		ao:${PORTSDIR}/audio/libao \
		mad:${PORTSDIR}/audio/libmad \
		avutil:${PORTSDIR}/multimedia/ffmpeg

RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_GCC=	any
USES=		cmake
USE_QT4=	gui qt3support xml  moc_build qmake_build rcc_build uic_build
CXXFLAGS+=	-I${LOCALBASE}/include \
		-I${LOCALBASE}/include/libavcodec \
		-I${LOCALBASE}/include/libavformat \
		-I${LOCALBASE}/include/libswscale

BROKEN=		Does not compile due to FFMPEG update - will be fixed soon

pre-patch:
		cd ${WRKSRC} && ${BZCAT} ${FILESDIR}/use-qt4.diff.bz2 | ${PATCH} -p2

post-build:
		$(SED) -e 's;@prefix@/dvbcut/share/icons;'${PREFIX}/share/icons/dvbcut';' \
			< ${WRKSRC}/dvbcut.desktop.in \
			> ${WRKSRC}/dvbcut.desktop

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/src/dvbcut ${STAGEDIR}${PREFIX}/bin/
		${INSTALL_MAN} ${WRKSRC}/dvbcut.1 ${STAGEDIR}${MANPREFIX}/man/man1/
		${MKDIR} $(STAGEDIR)$(PREFIX)/share/applications
	        $(INSTALL_DATA) ${WRKSRC}/dvbcut.desktop $(STAGEDIR)$(PREFIX)/share/applications/
		${MKDIR} $(STAGEDIR)$(PREFIX)/share/icons/dvbcut
	       	$(INSTALL_DATA) ${WRKSRC}/dvbcut.svg $(STAGEDIR)$(PREFIX)/share/icons/dvbcut/
	       	$(INSTALL_DATA) ${WRKSRC}/icons/* $(STAGEDIR)$(PREFIX)/share/icons/dvbcut/
		${MKDIR} $(STAGEDIR)$(PREFIX)/share/mime/packages
	       	$(INSTALL_DATA) ${WRKSRC}/dvbcut.xml $(STAGEDIR)$(PREFIX)/share/mime/packages/

.include <bsd.port.mk>
