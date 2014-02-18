# $FreeBSD$

PORTNAME=	kmplot
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	math kde
MASTER_SITES=	KDE/${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE/${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Mathematical function plotter for KDE 4

USE_KDE4=	kdehier kdelibs kdeprefix automoc4
USES=		cmake:outsource
USE_QT4=	xml moc_build qmake_build rcc_build uic_build
USE_XZ=		yes

.include <bsd.port.mk>
