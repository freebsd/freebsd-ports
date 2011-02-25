# New ports collection makefile for: bangarang
# Date created:        11 June 2010
# Whom:                Daniel Nebdal <dnebdal@gmail.com>
#
# $FreeBSD$

PORTNAME=      bangarang
PORTVERSION=   1.0.1
PORTREVISION=	1
CATEGORIES=    multimedia
MASTER_SITES=  http://opendesktop.org/CONTENT/content-files/
DISTNAME=      113305-bangarang-1.0.1
DIST_SUBDIR=   KDE

MAINTAINER=    dnebdal@gmail.com
COMMENT=       A media player for KDE4

LIB_DEPENDS=	kcddb.5:${PORTSDIR}/multimedia/kdemultimedia4

BROKEN=		does not compile

USE_CMAKE=     yes
USE_GMAKE=     yes
USE_QT_VER=    4
QT_COMPONENTS= qmake_build moc_build rcc_build uic_build
USE_KDE4=      automoc4 akonadi kdelibs kdeprefix kdebase kdeprefix

CMAKE_OUTSOURCE=	yes
MAKE_JOBS_UNSAFE=	yes

WRKSRC=        ${WRKDIR}/bangarang-bangarang

.include <bsd.port.mk>
