# New ports collection makefile for:	KMplayer-kde4
# Date created:				Aug 26, 2008
# Whom:					Kris Moore
#
# $FreeBSD$
#

PORTNAME=	kmplayer
DISTVERSION=	0.11.0-rc4
PORTREVISION=	1
PORTEPOCH=	2
CATEGORIES=	multimedia audio kde
MASTER_SITES=	http://kmplayer.kde.org/pkgs/
PKGNAMESUFFIX=	-kde4

MAINTAINER=	kris@pcbsd.org
COMMENT=	KDE frontend to Phonon / KDE4

RUN_DEPENDS=	mplayer:${PORTSDIR}/multimedia/mplayer

USE_BZIP2=	yes
USE_CMAKE=	yes
USE_KDE4=	automoc4 kdehier kdeprefix kdelibs
USE_QT_VER=	4
QT_COMPONENTS=	corelib qmake_build moc_build rcc_build uic_build
USE_LDCONFIG=	${KDE4_PREFIX}/lib ${KDE4_PREFIX}/lib/kde4

.include <bsd.port.mk>
