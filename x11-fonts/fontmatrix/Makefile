# $FreeBSD$

PORTNAME=	fontmatrix
DISTVERSION=	0.4.2
DISTVERSIONSUFFIX=	-Source
PORTREVISION=	4
CATEGORIES=	x11-fonts
MASTER_SITES=	http://www.fontmatrix.net/archives/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Graphical font manager

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${LOCALBASE}/share/icons/hicolor/index.theme:misc/hicolor-icon-theme
LIB_DEPENDS=	libfreetype.so:print/freetype2 \
		libfontconfig.so:x11-fonts/fontconfig

USES=		cmake
USE_QT4=	corelib xml gui svg network moc_build uic_build rcc_build qmake_build linguisttools_build
INSTALLS_ICONS=	yes

OPTIONS_DEFINE=	FONTFORGE
FONTFORGE_DESC=	Install FontForge editor
FONTFORGE_RUN_DEPENDS=	${LOCALBASE}/bin/fontforge:print/fontforge

post-patch:
	@${REINPLACE_CMD} -e 's:/usr/bin/fontforge:${LOCALBASE}/bin/fontforge:g' \
		${WRKSRC}/src/prefs_panel.ui ${WRKSRC}/src/typotek.cpp

pre-configure:
	cd ${WRKSRC}/src/messages && \
		${LUPDATE} -noobsolete ../ -ts *.ts && \
		${LRELEASE} *.ts

.include <bsd.port.mk>
