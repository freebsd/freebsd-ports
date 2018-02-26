# Created by: Kevin Zheng <kevinz5000@gmail.com>
# $FreeBSD$

PORTNAME=	qsynergy
PORTVERSION=	0.9.1
CATEGORIES=	sysutils
MASTER_SITES=	SF/${PORTNAME}/${PORTVERSION}

MAINTAINER=	kevinz5000@gmail.com
COMMENT=	Comprehensive and easy to use graphical front end for Synergy

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		qmake
USE_QT4=	moc_build rcc_build uic_build corelib gui network

PLIST_FILES=	bin/qsynergy \
		share/pixmaps/qsynergy.xpm

DESKTOP_ENTRIES=	"QSynergy" "Graphical front end for Synergy" \
			"${PREFIX}/share/pixmaps/qsynergy.xpm" \
			"${PORTNAME}" "Qt;Settings;System;" true

post-patch:
	@${REINPLACE_CMD} -e "s|/usr/bin|${PREFIX}/bin|" \
	    ${WRKSRC}/qsynergy.pro ${WRKSRC}/src/AppConfig.cpp

post-install:
	${INSTALL_DATA} ${WRKSRC}/dist/qsynergy.xpm \
	    ${STAGEDIR}/${PREFIX}/share/pixmaps

.include <bsd.port.mk>
