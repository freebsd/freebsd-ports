# New ports collection makefile for:    gtk-qt4-engine
# Date created:                         07 July 2008
# Whom:                                 Kris Moore <kris@pcbsd.org>
#
# $FreeBSD$
#

PORTNAME=	gtk-qt4-engine
PORTVERSION=	1.1
PORTREVISION=	1
CATEGORIES=	x11-themes
MASTER_SITES=	http://gtk-qt-engine.googlecode.com/files/
DISTFILES=	gtk-qt-engine-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	kris@pcbsd.org
COMMENT=	GTK-QT Theme Engine allows GTK2 apps to use QT/KDE themes

USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_GNOME=	gtk20
USE_QT_VER=	4
QT_COMPONENTS=	gui moc_build rcc_build uic_build qmake_build
USE_CMAKE=	yes
USE_KDE4=	kdebase kdeprefix automoc4

OPTIONS=	LIBBONOBOUI "Install libbonoboui if missing" off

WRKSRC=		${WRKDIR}/gtk-qt-engine

.include <bsd.port.pre.mk>

.if defined(WITH_LIBBONOBOUI)
USE_GNOME+=	libbonoboui
.endif

.include <bsd.port.post.mk>
