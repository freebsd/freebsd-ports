# $FreeBSD$

PORTNAME=	rocs
PORTVERSION=	${KDE4_VERSION}
PORTREVISION=	1
CATEGORIES=	math kde
MASTER_SITES=	KDE/${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE/${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE Graph theory IDE

LIB_DEPENDS=	libboost_thread.so:devel/boost-libs \
		libgrantlee_gui.so:devel/grantlee

USE_KDE4=	kdelibs kdeprefix automoc4
USES=		cmake:outsource tar:xz
USE_QT4=	gui qtestlib script scripttools webkit xml \
		moc_build qmake_build rcc_build uic_build
USE_LDCONFIG=	yes

.include <bsd.port.mk>
