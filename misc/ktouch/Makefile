# $FreeBSD$

PORTNAME=	ktouch
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	misc kde
MASTER_SITES=	KDE/${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE/${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Touch typing tutor for KDE 4

RUN_DEPENDS=	${LOCALBASE}/lib/kde4/imports/org/kde/charts/qmldir:graphics/kqtquickcharts

USE_KDE4=	kdelibs automoc4
USES=		cmake:outsource tar:xz
USE_QT4=	corelib declarative opengl phonon script sql xmlpatterns \
		moc_build qmake_build rcc_build uic_build
USE_XORG=	xkbfile

.include <bsd.port.mk>
