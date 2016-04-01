# $FreeBSD$

PORTNAME=	fontmatrix
DISTVERSION=	0.4.2
DISTVERSIONSUFFIX=	-Source
PORTREVISION=	4
CATEGORIES=	x11-fonts
MASTER_SITES=	http://www.fontmatrix.net/archives/

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Graphical font manager

RUN_DEPENDS=	${LOCALBASE}/share/icons/hicolor/index.theme:misc/hicolor-icon-theme

USES=		cmake
USE_QT4=	gui svg network moc_build uic_build rcc_build qmake_build linguisttools_build
INSTALLS_ICONS=	yes

OPTIONS_DEFINE=	FONTFORGE
FONTFORGE_DESC=	Install FontForge editor
FONTFORGE_RUN_DEPENDS=	${LOCALBASE}/bin/fontforge:print/fontforge

post-patch:
	cd ${WRKSRC}/src && \
		${REINPLACE_CMD} -e 's:/usr/bin/fontforge:${LOCALBASE}/bin/fontforge:g' \
		prefs_panel.ui \
		typotek.cpp

pre-configure:
	cd ${WRKSRC}/src/messages && \
		${LUPDATE} -noobsolete ../ -ts *.ts && \
		${LRELEASE} *.ts

.include <bsd.port.mk>
