# $FreeBSD$

PORTNAME=	rocs
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
PORTREVISION=	1
CATEGORIES=	math kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE Graph theory IDE

LIB_DEPENDS=	libboost_thread.so:devel/boost-libs

USES=		cmake compiler:c++11-lang desktop-file-utils gettext grantlee:5 kde:5 \
		qt:5 tar:xz
USE_KDE=	archive auth codecs completion config configwidgets coreaddons \
		crash doctools ecm i18n itemviews jobwidgets kdeclarative \
		kio package parts service sonnet texteditor textwidgets \
		widgetsaddons xmlgui
USE_QT=		concurrent core dbus declarative gui network script scripttools svg webkit \
		widgets xml xmlpatterns \
		buildtools_build qmake_build

USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
