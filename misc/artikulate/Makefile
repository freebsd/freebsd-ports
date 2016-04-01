# $FreeBSD$

PORTNAME=	artikulate
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	misc kde
MASTER_SITES=	KDE/${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE/${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Pronunciation trainer for KDE

LIB_DEPENDS=	libQtGStreamer-1.0.so:multimedia/gstreamer1-qt4 \
		libboost_thread.so:devel/boost-libs
RUN_DEPENDS=	${LOCALBASE}/lib/kde4/imports/org/kde/charts/qmldir:graphics/kqtquickcharts

IGNORE=		not usable, links to both GStreamer 0.10.x and 1.x

USE_KDE4=	automoc4 kdelibs kdeprefix libkdeedu runtime_run
USES=		cmake:outsource tar:xz
USE_QT4=	moc_build qmake_build rcc_build uic_build
USE_LDCONFIG=	yes

.include <bsd.port.mk>
