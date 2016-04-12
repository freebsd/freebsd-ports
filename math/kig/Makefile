# $FreeBSD$

PORTNAME=	kig
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	math kde
MASTER_SITES=	KDE/${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE/${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE 4 interactive geometry application

LIB_DEPENDS=	libboost_python.so:devel/boost-python-libs

USE_KDE4=	kdelibs kdeprefix automoc4
USES=		cmake:outsource compiler:c++11-lib tar:xz
USE_QT4=	gui xml moc_build qmake_build rcc_build uic_build

.include <bsd.port.mk>
