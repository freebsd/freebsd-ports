# Created by: Kris Moore <kris@pcbsd.org>
# $FreeBSD$

PORTNAME=	gtk-qt-engine
PORTVERSION=	1.1
PORTREVISION=	12
CATEGORIES=	x11-themes
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}

MAINTAINER=	makc@FreeBSD.org
COMMENT=	GTK+ 2.x theme engine allowing to use Qt/KDE styles

USE_GNOME=	gtk20
USE_QT4=	corelib gui moc_build rcc_build uic_build qmake_build
USES=		cmake gettext pkgconfig tar:bzip2
USE_KDE4=	kdelibs kdeprefix automoc4
WRKSRC=		${WRKDIR}/${PORTNAME}

OPTIONS_DEFINE=	BONOBO
BONOBO_DESC=	Better support for Bonobo (GNOME) framework

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MBONOBO}
USE_GNOME+=	libbonoboui
.endif

post-patch:
.if !${PORT_OPTIONS:MBONOBO}
	@${REINPLACE_CMD} -e '/^PKGCONFIG(libbonoboui/d' \
		${WRKSRC}/CMakeLists.txt
.endif
	@${REINPLACE_CMD} -e 's,/usr/local,${LOCALBASE},g' \
		${WRKSRC}/kcm_gtk/searchpaths.cpp \
		${WRKSRC}/src/rcproperties.cpp

.include <bsd.port.mk>
