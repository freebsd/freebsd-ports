# $FreeBSD$

PORTNAME=	messagelib
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	net kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Library for handling messages

LICENSE=	LGPL21

LIB_DEPENDS=	libassuan.so:security/libassuan \
		libboost_system.so:devel/boost-libs \
		libgpg-error.so:security/libgpg-error \
		libgpgme.so:security/gpgme \
		libgpgmepp.so:security/gpgme-cpp \
		libqgpgme.so:security/gpgme-qt5

USES=		cmake compiler:c++11-lib gettext grantlee:5 kde:5 qt:5 tar:xz
USE_KDE=	archive auth bookmarks codecs completion config configwidgets \
		coreaddons ecm i18n iconthemes itemmodels itemviews jobwidgets \
		kdewebkit kio service solid sonnet syntaxhighlighting \
		textwidgets wallet widgetsaddons windowsystem xmlgui
# pim components
USE_KDE+=	akonadi akonadicontacts akonadimime akonadisearch calendarcore \
		contacts grantleetheme gravatar identitymanagement \
		kdepim-apps-libs ldap libkdepim libkleo mailtransport mbox \
		mime pimcommon pimtextedit
USE_QT=		core dbus declarative gui location network printsupport testlib \
		uitools webchannel webengine widgets xml \
		buildtools_build qmake_build
USE_LDCONFIG=	yes


OPTIONS_DEFINE=		INOTIFY DOCS
OPTIONS_DEFAULT=	INOTIFY
OPTIONS_SUB=		yes

INOTIFY_DESC=		Filesystem alteration notifications using inotify
INOTIFY_LIB_DEPENDS=	libinotify.so:devel/libinotify

.include <bsd.port.mk>
