# New ports collection makefile for:	phonon-vlc
# Date created:		2010-07-25
# Whom:			Max Brazhnikov <makc@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	phonon
PORTVERSION=	0.2.0
CATEGORIES=	multimedia kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/phonon-backend-vlc/${PORTVERSION}/src
PKGNAMESUFFIX=	-vlc
DISTNAME=	phonon-backend-vlc-${PORTVERSION}
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	The VLC backend for Phonon

LIB_DEPENDS=	vlc.5:${PORTSDIR}/multimedia/vlc

USE_CMAKE=	yes
USE_KDE4=	kdehier automoc4 kdeprefix
USE_QT_VER=	4
QT_COMPONENTS=	dbus phonon \
		qmake_build moc_build rcc_build uic_build
MAKE_JOBS_SAFE=	yes

.include <bsd.port.mk>
