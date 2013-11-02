# Created by: Kris Moore
# $FreeBSD$

PORTNAME=	kmplayer
PORTVERSION=	0.11.3d
PORTEPOCH=	3
CATEGORIES=	multimedia audio kde
MASTER_SITES=	http://kmplayer.kde.org/pkgs/
PKGNAMESUFFIX=	-kde4

MAINTAINER=	ports@FreeBSD.org
COMMENT=	KDE frontend to Phonon / KDE4

LICENSE=	GPLv2 LGPL21
LICENSE_COMB=	multi

LIB_DEPENDS=	libdbus-glib-1.so:${PORTSDIR}/devel/dbus-glib \
		libcairo.so:${PORTSDIR}/graphics/cairo
RUN_DEPENDS=	mplayer:${PORTSDIR}/multimedia/mplayer

USE_BZIP2=	yes
USES=		cmake pkgconfig
USE_GNOME=	gtk20
USE_QT4=	corelib moc_build qmake_build rcc_build uic_build
USE_KDE4=	automoc4 kdelibs kdeprefix

.include <bsd.port.mk>
