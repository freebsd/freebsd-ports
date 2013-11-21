# $FreeBSD$

PORTNAME=	beediff
PORTVERSION=	1.9
PORTREVISION=	3
CATEGORIES=	textproc devel
MASTER_SITES=	http://www.beesoft.pl/download/
DISTNAME=	${PORTNAME}_${PORTVERSION}_src

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Qt 4 based diff frontend

USES=		qmake
USE_QT4=	gui moc_build rcc_build

WRKSRC=		${WRKDIR}/${PORTNAME}

PLIST_FILES=	bin/beediff share/pixmaps/beediff.png

DESKTOP_ENTRIES="BeeDiff" "diff frontend" \
		"${PREFIX}/share/pixmaps/${PORTNAME}.png" \
		"beediff" "" true

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/beediff ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/img/beediff.png ${STAGEDIR}${PREFIX}/share/pixmaps

.include <bsd.port.mk>
