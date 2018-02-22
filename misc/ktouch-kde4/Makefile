# $FreeBSD$

PORTNAME=	ktouch
PORTVERSION=	${KDE4_VERSION}
PORTREVISION=	3
CATEGORIES=	misc kde kde-kde4

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Touch typing tutor for KDE 4

RUN_DEPENDS=	${LOCALBASE}/lib/kde4/imports/org/kde/charts/qmldir:graphics/kqtquickcharts-kde4

USES=		cmake:outsource kde:4 tar:xz
USE_KDE=	kdelibs automoc4
USE_QT4=	corelib declarative opengl phonon script sql xmlpatterns \
		moc_build qmake_build rcc_build uic_build
USE_XORG=	xkbfile

.include <bsd.port.mk>
