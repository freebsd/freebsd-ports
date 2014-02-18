# Created by: Raphael Kubo da Costa <rakuco@FreeBSD.org>
# $FreeBSD$

PORTNAME=	dragon
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	multimedia kde
MASTER_SITES=	KDE/${KDE4_BRANCH}/${PORTVERSION}/src
# Avoid clash with devel/dragon
PKGNAMESUFFIX=	-player
DIST_SUBDIR=	KDE/${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE multimedia player with a focus on simplicity

LICENSE=	GPLv2

USES=		cmake:outsource
USE_KDE4=	automoc4 kdehier kdelibs kdeprefix
USE_QT4=	phonon moc_build qmake_build rcc_build uic_build
USE_XZ=		yes

.include <bsd.port.mk>
