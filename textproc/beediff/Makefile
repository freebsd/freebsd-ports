# New ports collection makefile for:	beediff
# Date created:		2008-03-23
# Whom:			Max Brazhnikov <makc@issp.ac.ru>
#
# $FreeBSD$
#

PORTNAME=	beediff
PORTVERSION=	1.8
CATEGORIES=	textproc devel
MASTER_SITES=	http://www.beesoft.org/download/
DISTNAME=	${PORTNAME}_${PORTVERSION}_src

MAINTAINER=	makc@issp.ac.ru
COMMENT=	QT4 based diff frontend

USE_QT_VER=	4
QT_COMPONENTS=	gui moc_build rcc_build qmake_build
HAS_CONFIGURE=	yes
INSTALLS_ICONS=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}

PLIST_FILES=	bin/beediff share/pixmaps/beediff.png

DESKTOP_ENTRIES="BeeDiff" "diff frontend" "beediff.png" \
		"beediff" "" false

do-configure:
	cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ${QMAKE}

post-configure:
	@${REINPLACE_CMD} -e \
			's|^CC .*|CC=${CC}|; \
			s|^CXX .*|CXX=${CXX}|; \
			s|^LINK .*|LINK=${CXX}|' \
			${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/beediff ${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/img/beediff.png ${PREFIX}/share/pixmaps/

.include <bsd.port.mk>
