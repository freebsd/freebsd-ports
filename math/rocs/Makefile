PORTNAME=	rocs
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
PORTREVISION=	1
CATEGORIES=	math education kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE Graph theory IDE
WWW=		https://www.kde.org/applications/education/rocs

LIB_DEPENDS=	libboost_thread.so:devel/boost-libs

USES=		cmake compiler:c++11-lang desktop-file-utils gettext \
		grantlee:5 kde:5 qt:5 tar:xz xorg
USE_KDE=	archive auth codecs completion config configwidgets coreaddons \
		crash i18n itemviews jobwidgets kdeclarative kio package parts \
		service solid sonnet syntaxhighlighting texteditor textwidgets \
		widgetsaddons windowsystem xmlgui \
		doctools:build ecm:build
USE_QT=		concurrent core dbus declarative gui network script \
		scripttools svg widgets xml xmlpatterns \
		buildtools:build qmake:build testlib:build
USE_XORG=	x11
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
