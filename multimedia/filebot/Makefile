# $FreeBSD$

PORTNAME=	filebot
DISTVERSION=	4.9.3
CATEGORIES=	multimedia java
MASTER_SITES=	https://get.filebot.net/filebot/FileBot_${DISTVERSION}/
DISTNAME=	FileBot_${DISTVERSION}-portable

MAINTAINER=	dan.kotowski@a9development.com
COMMENT=	FileBot is the ultimate tool for organizing and renaming your media

LICENSE=	FileBot_EULA
LICENSE_NAME=	FileBot End User License Agreement
LICENSE_TEXT=	Description of the license can be obtained from the following URL: \
		https://www.filebot.net/eula.html
LICENSE_PERMS=	dist-mirror pkg-mirror auto-accept

LIB_DEPENDS=	libmediainfo.so:multimedia/libmediainfo \
				libfontconfig.so:x11-fonts/fontconfig
RUN_DEPENDS=	ffprobe:multimedia/ffmpeg \
				chromaprint>0:audio/chromaprint \
				jna>0:devel/jna \
				openjfx14>0:java/openjfx14

USES=	tar:xz
USE_JAVA=	yes
JAVA_VERSION=	11

NO_WRKSUBDIR=	yes
NO_BUILD=	yes
NO_INSTALL=	yes
NO_TEST=	yes

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/${PORTNAME}/jar
	${INSTALL_SCRIPT} ${WRKSRC}/filebot.sh ${STAGEDIR}${PREFIX}/share/${PORTNAME}/
	@cd ${WRKSRC}/jar && \
		${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/share/${PORTNAME}/jar/
	${RLN} ${STAGEDIR}${PREFIX}/share/${PORTNAME}/filebot.sh ${STAGEDIR}${PREFIX}/bin/filebot

.include <bsd.port.mk>
