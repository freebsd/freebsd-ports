PORTNAME=	markdownpart
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	textproc kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KPart for rendering Markdown content
WWW=		https://invent.kde.org/utilities/markdownpart

USES=		cmake compiler:c++11-lang kde:5 qt:5 tar:xz xorg
USE_KDE=	auth codecs completion config configwidgets coreaddons i18n \
		jobwidgets kio parts service solid sonnet textwidgets widgetsaddons \
		windowsystem xmlgui \
		ecm:build
USE_QT=		concurrent core dbus gui network widgets xml \
		buildtools:build qmake:build
USE_XORG=	x11

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
