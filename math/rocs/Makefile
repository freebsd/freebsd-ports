# $FreeBSD$

PORTNAME=	rocs
PORTVERSION=	${KDE4_VERSION}
PORTREVISION=	7
CATEGORIES=	math kde kde-kde4

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE Graph theory IDE

LIB_DEPENDS=	libboost_thread.so:devel/boost-libs

USES=		cmake:outsource grantlee:4 kde:4 tar:xz
USE_KDE=	kdelibs automoc4
USE_QT4=	gui qtestlib script scripttools webkit xml \
		moc_build qmake_build rcc_build uic_build
USE_LDCONFIG=	yes

.include <bsd.port.mk>
