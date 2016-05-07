# Created by: Kris Moore
# $FreeBSD$

PORTNAME=	kmplayer
PORTVERSION=	0.11.5
PORTEPOCH=	3
CATEGORIES=	multimedia audio kde
PKGNAMESUFFIX=	-kde4

MAINTAINER=	ports@FreeBSD.org
COMMENT=	KDE frontend to Phonon / KDE4

LICENSE=	GPLv2 LGPL21
LICENSE_COMB=	multi

LIB_DEPENDS=	libdbus-glib-1.so:devel/dbus-glib
RUN_DEPENDS=	mplayer:multimedia/mplayer

USES=		cmake:outsource pkgconfig
USE_GNOME=	cairo gtk20
USE_QT4=	corelib moc_build qmake_build rcc_build uic_build
USE_KDE4=	automoc4 kdelibs kdeprefix

USE_GITHUB=	yes
GH_ACCOUNT=	KDE

.include <bsd.port.mk>
