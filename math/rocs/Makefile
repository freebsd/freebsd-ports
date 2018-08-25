# $FreeBSD$

PORTNAME=	rocs
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	math kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE Graph theory IDE

LIB_DEPENDS=	libboost_thread.so:devel/boost-libs

USES=		cmake:outsource gettext grantlee:5 kde:5 qt:5 tar:xz
USE_KDE=	archive auth codecs completion config configwidgets coreaddons \
		crash doctools ecm i18n itemviews jobwidgets kdeclarative \
		kio package parts service sonnet texteditor textwidgets \
		widgetsaddons xmlgui
USE_QT=		core dbus gui network qml script quick scripttools svg webkit \
		widgets xml xmlpatterns \
		buildtools_build qmake_build

USE_LDCONFIG=	yes

# clang 6.0 defaults to -std=gnu++14, which breaks the build:
# /wrkdirs/usr/ports/math/rocs/work/rocs-4.14.3/VisualEditor/Actions/SelectMoveHandAction.cpp:86:52: error: no viable conversion from 'int' to 'QPainter::RenderHints' (aka 'QFlags<QPainter::RenderHint>')
#         _graphScene->views().at(0)->setRenderHints(QPainter::Antialiasing
USE_CXXSTD=	gnu++98

.include <bsd.port.mk>
