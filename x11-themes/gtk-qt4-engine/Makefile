# Created by: Kris Moore <kris@pcbsd.org>
# $FreeBSD$

PORTNAME=	gtk-qt-engine
PORTVERSION=	1.1
PORTREVISION=	16
CATEGORIES=	x11-themes

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GTK+ 2.x theme engine allowing to use Qt/KDE styles

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

DEPRECATED=		Qt4 has been EOL since december 2015
EXPIRATION_DATE=	2018-12-31

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2

USE_GITHUB=	yes
GH_ACCOUNT=	davidsansome
GH_TAGNAME=	0dc6c26

USES=		cmake:insource gettext kde:4 pkgconfig qt:4
USE_GNOME=	cairo gdkpixbuf2 gtk20
USE_KDE=	kdelibs automoc4
USE_QT=		dbus corelib gui moc_build rcc_build uic_build qmake_build svg
USE_XORG=	x11
WRKSRC_SUBDIR=	${PORTNAME}

OPTIONS_DEFINE=	BONOBO
BONOBO_DESC=	Better support for Bonobo (GNOME) framework
BONOBO_USE=	GNOME=libbonoboui

post-patch:
	@${REINPLACE_CMD} -e 's,/usr/local,${LOCALBASE},g' \
		${WRKSRC}/kcm_gtk/searchpaths.cpp \
		${WRKSRC}/src/rcproperties.cpp

post-patch-BONOBO-off:
	${REINPLACE_CMD} -e '/^PKGCONFIG(libbonoboui/d' \
		${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
