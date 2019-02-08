# $FreeBSD$

PORTNAME=	kgpg
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	security kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Encryption tool for KDE

RUN_DEPENDS=	gpg2:security/gnupg

USES=		cmake compiler:c++11-lang gettext kde:5 qt:5 \
		tar:xz
USE_KDE=	akonadi akonadicontacts archive auth bookmarks codecs \
		completion config configwidgets contacts coreaddons crash \
		dbusaddons doctools ecm i18n iconthemes itemmodels itemviews \
		jobwidgets kio notifications service solid sonnet textwidgets \
		widgetsaddons windowsystem xmlgui
USE_QT=		core dbus gui network printsupport widgets xml \
		buildtools_build qmake_build

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
