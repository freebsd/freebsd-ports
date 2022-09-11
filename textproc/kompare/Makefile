PORTNAME=	kompare
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	textproc kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Diff/Patch Frontend

LIB_DEPENDS=	libkomparediff2.so:textproc/libkomparediff2

USES=		cmake compiler:c++11-lang desktop-file-utils gettext \
		kde:5 qt:5 tar:xz xorg
USE_KDE=	auth codecs completion config configwidgets coreaddons \
		doctools i18n iconthemes jobwidgets kio parts service \
		solid sonnet syntaxhighlighting texteditor textwidgets widgetsaddons \
		windowsystem xmlgui \
		ecm:build
USE_QT=		concurrent core dbus gui network printsupport widgets xml \
		buildtools:build qmake:build
USE_XORG=	x11

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
