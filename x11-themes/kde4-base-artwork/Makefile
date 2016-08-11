# Created by: Raphael Kubo da Costa <rakuco@FreeBSD.org>
# $FreeBSD$

PORTNAME=	kde-base-artwork
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	x11-themes kde
MASTER_SITES=	KDE/${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE/${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Base artwork for the KDE Plasma Desktop

LICENSE=	GPLv2

USES=		cmake:outsource tar:xz
USE_KDE4=	automoc4 kdelibs
USE_QT4=	moc_build qmake_build rcc_build uic_build
NO_BUILD=	yes

.include <bsd.port.mk>
