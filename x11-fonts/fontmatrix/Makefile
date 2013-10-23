# $FreeBSD$

PORTNAME=	fontmatrix
DISTVERSION=	0.4.2
DISTVERSIONSUFFIX=	-Source
PORTREVISION=	4
CATEGORIES=	x11-fonts
MASTER_SITES=	http://www.fontmatrix.net/archives/

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Graphical font manager

RUN_DEPENDS=	${LOCALBASE}/share/icons/hicolor/index.theme:${PORTSDIR}/misc/hicolor-icon-theme

USES=		cmake
USE_QT4=	gui svg network moc_build uic_build rcc_build qmake_build linguist_build
INSTALLS_ICONS=	yes

OPTIONS_DEFINE=	FONTFORGE
FONTFORGE_DESC=	Install FontForge editor
FONTFORGE_RUN_DEPENDS=	${LOCALBASE}/bin/fontforge:${PORTSDIR}/print/fontforge

post-patch:
	cd ${WRKSRC}/src && \
		${REINPLACE_CMD} -e 's:/usr/bin/fontforge:${LOCALBASE}/bin/fontforge:g' \
		prefs_panel.ui \
		typotek.cpp

pre-configure:
	cd ${WRKSRC}/src/messages && \
		${LOCALBASE}/bin/lupdate-qt4 -noobsolete ../ -ts *.ts && \
		${LOCALBASE}/bin/lrelease-qt4 *.ts

.include <bsd.port.mk>
