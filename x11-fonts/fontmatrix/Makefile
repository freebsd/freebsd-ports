# $FreeBSD$

PORTNAME=	fontmatrix
DISTVERSIONPREFIX=	v
DISTVERSION=	0.6.0
CATEGORIES=	x11-fonts

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Graphical font manager

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_armv6=		fails to compile: src/fminfodisplay.cpp:155:17: no matching function for call to 'qMax'
BROKEN_armv7=		fails to compile: src/fminfodisplay.cpp:155:17: no matching function for call to 'qMax'

RUN_DEPENDS=	${LOCALBASE}/share/icons/hicolor/index.theme:misc/hicolor-icon-theme
LIB_DEPENDS=	libfreetype.so:print/freetype2 \
		libfontconfig.so:x11-fonts/fontconfig

USE_GITHUB=	yes
GH_ACCOUNT=	fontmatrix

USES=		cmake
USE_QT4=	corelib xml gui svg network moc_build uic_build rcc_build qmake_build \
		linguisttools_build opengl sql webkit
INSTALLS_ICONS=	yes
MANDIRS=	${PREFIX}/share/man/man1

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
