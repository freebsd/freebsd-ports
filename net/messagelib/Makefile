PORTNAME=	messagelib
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
PORTREVISION=	1
CATEGORIES=	net kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Library for handling messages

LICENSE=	LGPL21

BUILD_DEPENDS=	${LOCALBASE}/include/boost/range/algorithm.hpp:devel/boost-libs
LIB_DEPENDS=	libassuan.so:security/libassuan \
		libgpg-error.so:security/libgpg-error \
		libgpgme.so:security/gpgme \
		libgpgmepp.so:security/gpgme-cpp \
		libqgpgme.so:security/gpgme-qt5

USES=		cmake compiler:c++11-lib cpe gettext grantlee:5 kde:5 qca qt:5 tar:xz
CPE_VENDOR=	kde
USE_KDE=	archive auth bookmarks codecs completion config configwidgets \
		coreaddons guiaddons i18n iconthemes imap itemmodels itemviews jobwidgets \
		kdewebkit kio service solid sonnet syntaxhighlighting \
		textwidgets wallet widgetsaddons windowsystem xmlgui \
		ecm_build
# pim components
USE_KDE+=	akonadi akonadicontacts akonadimime akonadisearch calendarcore \
		contacts grantleetheme gravatar identitymanagement \
		ldap libkdepim libkleo mailtransport mbox \
		mime pimcommon pimtextedit
USE_QT=		concurrent core dbus declarative gui location network printsupport \
		uitools webchannel webengine widgets xml \
		buildtools_build qmake_build testlib_build
USE_LDCONFIG=	yes

OPTIONS_DEFINE=		INOTIFY DOCS
OPTIONS_DEFAULT=	INOTIFY
OPTIONS_SUB=		yes

INOTIFY_DESC=		Filesystem alteration notifications using inotify
INOTIFY_LIB_DEPENDS=	libinotify.so:devel/libinotify

.include <bsd.port.mk>
