# Created by: Kris Moore <kris@pcbsd.org>
# $FreeBSD$

PORTNAME=	gtk-qt-engine
PORTVERSION=	1.1
PORTREVISION=	12
CATEGORIES=	x11-themes
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	makc@FreeBSD.org
COMMENT=	GTK+ 2.x theme engine allowing to use Qt/KDE styles

USE_GNOME=	gtk20
USE_QT4=	corelib gui moc_build rcc_build uic_build qmake_build
USES=		cmake gettext pkgconfig tar:bzip2
USE_KDE4=	kdelibs automoc4
WRKSRC=		${WRKDIR}/${PORTNAME}

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
