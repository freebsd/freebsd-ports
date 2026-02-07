PORTNAME=	qwinff
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.1-22
DISTVERSIONSUFFIX=	-g17e987e
PORTREVISION=	1
CATEGORIES=	multimedia

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Qt5 GUI Frontend for FFmpeg
WWW=		https://qwinff.github.io/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING.txt

RUN_DEPENDS=	ffmpeg:multimedia/ffmpeg \
		sox:audio/sox

USES=		cmake:noninja compiler:c++11-lang qt:5
USE_GITHUB=	yes
USE_QT=		core gui linguisttools network widgets buildtools:build \
		qmake:build

post-patch:
	@${REINPLACE_CMD} -e "s|%%DATADIR%%|${DATADIR}|" \
		${WRKSRC}/src/main.cpp ${WRKSRC}/src/ui/mainwindow.cpp

.include <bsd.port.mk>
