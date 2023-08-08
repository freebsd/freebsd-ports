PORTNAME=	kgpg
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	security kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Encryption tool for KDE
WWW=		https://utils.kde.org/projects/kgpg/

RUN_DEPENDS=	gpg2:security/gnupg

USES=		cmake compiler:c++11-lang cpe desktop-file-utils gettext grantlee:5 \
		kde:5 pkgconfig qt:5 tar:xz xorg
USE_KDE=	akonadi akonadicontacts archive auth bookmarks codecs \
		completion config configwidgets contacts coreaddons crash \
		dbusaddons doctools grantleetheme i18n iconthemes itemmodels itemviews \
		jobwidgets kio notifications service solid sonnet textwidgets \
		widgetsaddons windowsystem xmlgui \
		ecm:build
USE_QT=		concurrent core dbus gui network printsupport widgets xml \
		buildtools:build qmake:build
USE_XORG=	x11

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
