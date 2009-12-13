# New ports collection makefile for:	clipgrab
# Date created:		2009-12-06
# Whom:			Gvozdikov Veniamin <g.veniamin@googlemail.com>
#
# $FreeBSD$
#

PORTNAME=	clipgrab
PORTVERSION=	3.0.4.1
CATEGORIES=	multimedia
MASTER_SITES=	http://clipgrab.de/download/
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	g.veniamin@googlemail.com
COMMENT=	Program to download videos from YouTube and etc

USE_BZIP2=	yes
USE_QT_VER=	4
QT_COMPONENTS=	gui xml qmake_build uic_build moc_build \
		rcc_build network

PLIST_FILES=	bin/${PORTNAME} \
		share/${PORTNAME}/icon.png \
		share/${PORTNAME}/logo.png \
		share/${PORTNAME}/splash.png
PLIST_DIRS=	share/${PORTNAME}

post-patch:
	${REINPLACE_CMD} -e 's,img/,share/${PORTNAME}/,g' \
	${WRKSRC}/*.cpp

do-configure:
	cd ${WRKSRC} && ${QMAKE}

do-install:
	${MKDIR} ${DATADIR}
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/*.png ${DATADIR}

.include <bsd.port.mk>
