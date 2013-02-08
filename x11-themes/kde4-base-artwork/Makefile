# Created by: Raphael Kubo da Costa <rakuco@FreeBSD.org>
# $FreeBSD$

PORTNAME=		kde-base-artwork
PORTVERSION=		${KDE4_VERSION}
CATEGORIES=		x11-themes kde
MASTER_SITES=		${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=		KDE

MAINTAINER=		kde@FreeBSD.org
COMMENT=		Base artwork for the KDE4 Plasma Desktop

LICENSE=		GPLv2

CONFLICTS_INSTALL=	kde-workspace-4.[7-8].*

USE_KDE4=		automoc4 kdehier kdelibs kdeprefix
USE_QT4=		moc_build qmake_build rcc_build uic_build
KDE4_BUILDENV=		yes
NO_BUILD=		yes
USE_XZ=			yes

.include <bsd.port.mk>
