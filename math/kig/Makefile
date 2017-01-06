# $FreeBSD$

PORTNAME=	kig
PORTVERSION=	${KDE4_VERSION}
PORTREVISION=	2
CATEGORIES=	math kde kde-kde4

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE 4 interactive geometry application

LIB_DEPENDS=	libboost_python.so:devel/boost-python-libs

USES=		cmake:outsource compiler:c++11-lib kde:4 tar:xz
USE_KDE=	kdelibs automoc4
USE_QT4=	gui xml moc_build qmake_build rcc_build uic_build

.include <bsd.port.mk>
