# New ports collection makefile for:	qtcurve
# Date created:		2008-08-31
# Whom:			Max Brazhnikov <makc@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	qtcurve
PORTVERSION=	1.8.9
CATEGORIES=	x11-themes
MASTER_SITES=	http://craigd.wikispaces.com/file/view/
PKGNAMEPREFIX=	kde4-style-
DISTNAME=	QtCurve-KDE4-${PORTVERSION}

MAINTAINER=	makc@FreeBSD.org
COMMENT=	QtCurve KDE4 widget style

USE_BZIP2=	yes
USE_CMAKE=	yes
USE_QT_VER=	4
QT_COMPONENTS=	corelib qmake_build uic_build moc_build rcc_build
USE_KDE4=	kdelibs workspace kdehier kdeprefix automoc4

.include <bsd.port.mk>
