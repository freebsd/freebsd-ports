# $FreeBSD$

PORTNAME=	rocs
PORTVERSION=	${KDE4_VERSION}
PORTREVISION=	13
CATEGORIES=	math kde kde-kde4

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE Graph theory IDE

DEPRECATED=	KDE4 is EOL upstream
EXPIRATION_DATE=	2018-12-31

LIB_DEPENDS=	libboost_thread.so:devel/boost-libs

USES=		cmake grantlee:4 kde:4 qt:4 tar:xz
USE_KDE=	kdelibs automoc4
USE_QT=		gui qtestlib script scripttools webkit xml \
		moc_build qmake_build rcc_build uic_build
USE_LDCONFIG=	yes

# clang 6.0 defaults to -std=gnu++14, which breaks the build:
# /wrkdirs/usr/ports/math/rocs/work/rocs-4.14.3/VisualEditor/Actions/SelectMoveHandAction.cpp:86:52: error: no viable conversion from 'int' to 'QPainter::RenderHints' (aka 'QFlags<QPainter::RenderHint>')
#         _graphScene->views().at(0)->setRenderHints(QPainter::Antialiasing
USE_CXXSTD=	gnu++98

.include <bsd.port.mk>
