# $FreeBSD$

PORTNAME=	khelpcenter
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
PORTREVISION=	1
CATEGORIES=	sysutils kde kde-applications # kde kde-applications-plasma

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Plasma5 application to show KDE application documentation

LIB_DEPENDS=	libxapian.so:databases/xapian-core

USES=		cmake:outsource compiler:c++11-lib cpe gettext grantlee:5 \
		kde:5 qt:5 shebangfix tar:xz
USE_GNOME=	libxml2
USE_KDE=	archive auth bookmarks codecs completion config configwidgets \
		coreaddons dbusaddons doctools ecm emoticons i18n init \
		itemmodels itemviews jobwidgets js kcmutils kdelibs4support \
		kio khtml parts service sonnet textwidgets widgetsaddons \
		windowsystem xmlgui
USE_QT=		core dbus gui network widgets xml \
		buildtools_build qmake_build
SHEBANG_FILES=	searchhandlers/khc_mansearch.pl

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
