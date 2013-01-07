# $FreeBSD$

PORTNAME=	beediff
PORTVERSION=	1.9
PORTREVISION=	2
CATEGORIES=	textproc devel
MASTER_SITES=	http://www.beesoft.pl/download/
DISTNAME=	${PORTNAME}_${PORTVERSION}_src

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Qt4 based diff frontend

USE_QT4=	gui moc_build rcc_build qmake_build
HAS_CONFIGURE=	yes
INSTALLS_ICONS=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}

PLIST_FILES=	bin/beediff share/pixmaps/beediff.png

DESKTOP_ENTRIES="BeeDiff" "diff frontend" \
		"${PREFIX}/share/pixmaps/${PORTNAME}.png" \
		"beediff" "" false

do-configure:
	cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ${QMAKE} ${QMAKEFLAGS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/beediff ${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/img/beediff.png ${PREFIX}/share/pixmaps/

.include <bsd.port.mk>
