# Created by: Kris Moore
# $FreeBSD$

PORTNAME=	kmplayer
PORTVERSION=	0.11.2b
PORTREVISION=	2
PORTEPOCH=	3
CATEGORIES=	multimedia audio kde
MASTER_SITES=	http://kmplayer.kde.org/pkgs/
PKGNAMESUFFIX=	-kde4

MAINTAINER=	ports@freebsd.org
COMMENT=	KDE frontend to Phonon / KDE4

LIB_DEPENDS=	dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib \
		cairo.2:${PORTSDIR}/graphics/cairo
RUN_DEPENDS=	mplayer:${PORTSDIR}/multimedia/mplayer

USE_GNOME=	gtk20
USE_BZIP2=	yes
USES=		cmake
USE_KDE4=	automoc4 kdehier kdeprefix kdelibs
USE_QT4=	corelib qmake_build moc_build rcc_build uic_build

NO_STAGE=	yes
post-patch:
#Fix build with kdelibs>=4.5.0
	${REINPLACE_CMD} -e 's,V4.1.2-Based,V4.2-Based,g' \
		${WRKSRC}/doc/index.docbook
	${REINPLACE_CMD} -e 's,glib/gthread.h,glib.h,g' \
		${WRKSRC}/src/npplayer.cpp

.include <bsd.port.mk>
