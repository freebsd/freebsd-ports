# New ports collection makefile for:   skulpture
# Date created:                        Thu Dec  3 04:12:48  EST 2009
# Whom:                                Steve Wills <steve@mouf.net>
#
# $FreeBSD$
#

PORTNAME=	skulpture
PORTVERSION=	0.2.3
PORTREVISION=	4
CATEGORIES=	x11-themes kde
MASTER_SITES=	http://www.kde-look.org/CONTENT/content-files/
PKGNAMEPREFIX=	kde4-style-
DISTFILES=	59031-skulpture-${PORTVERSION}.tar.bz2

MAINTAINER=	swills@FreeBSD.org
COMMENT=	KDE style featuring 3d artwork and enhanced the visual experience

USE_BZIP2=	yes
USE_KDE4=	kdelibs kdehier kdeprefix automoc4 workspace
USE_QT_VER=	4
QT_COMPONENTS=	corelib qmake_build moc_build rcc_build uic_build
USE_CMAKE=	yes

.include <bsd.port.mk>
