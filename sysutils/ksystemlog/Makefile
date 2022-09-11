PORTNAME=	ksystemlog
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	sysutils kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE system log application
WWW=		https://kde.org/applications/system/ksystemlog/

USES=		cmake compiler:c++11-lang gettext kde:5 pkgconfig \
		qt:5 tar:xz xorg
USE_KDE=	archive auth codecs completion config configwidgets coreaddons \
		doctools i18n iconthemes itemviews jobwidgets kio \
		service solid sonnet textwidgets widgetsaddons windowsystem xmlgui \
		ecm:build
USE_QT=		concurrent core dbus gui network printsupport testlib widgets xml \
		buildtools:build qmake:build
USE_XORG=	x11

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
