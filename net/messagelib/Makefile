PORTNAME=	messagelib
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
PORTREVISION=	1
CATEGORIES=	net kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Library for handling messages
WWW=		https://github.com/KDE/messagelib

LICENSE=	LGPL21

IGNORE_FreeBSD_13=	is not supported on systems with OpenSSL 1.1.1

BUILD_DEPENDS=	${LOCALBASE}/include/boost/range/algorithm.hpp:devel/boost-libs
LIB_DEPENDS=	libassuan.so:security/libassuan \
		libgpg-error.so:security/libgpg-error \
		libgpgme.so:security/gpgme \
		libgpgmepp.so:security/gpgmepp \
		libqca-qt6.so:devel/qca@qt6 \
		libqgpgmeqt6.so:security/qgpgme@qt6

USES=		cmake compiler:c++11-lib cpe gettext kde:6 qt:6 tar:xz \
		xorg
CPE_VENDOR=	kde
USE_KDE=	archive auth bookmarks codecs completion config configwidgets \
		coreaddons guiaddons i18n iconthemes imap itemmodels itemviews \
		jobwidgets kio ktextaddons notifications service solid sonnet \
		syntaxhighlighting textwidgets wallet widgetsaddons \
		windowsystem xmlgui \
		ecm:build
# pim components
USE_KDE+=	akonadi akonadicontacts akonadimime akonadisearch calendarcore \
		contacts grantleetheme gravatar identitymanagement ldap \
		libkdepim libkleo mailtransport mbox mime pimcommon \
		pimtextedit
USE_QT=		base
USE_XORG=	x11
USE_LDCONFIG=	yes

OPTIONS_DEFINE=		INOTIFY DOCS
OPTIONS_DEFAULT=	INOTIFY
OPTIONS_SUB=		yes

INOTIFY_DESC=		Filesystem alteration notifications using inotify
INOTIFY_LIB_DEPENDS=	libinotify.so:devel/libinotify

.include <bsd.port.pre.mk>

.if ${COMPILER_TYPE} == clang
CXXFLAGS+=	-D_LIBCPP_ENABLE_CXX17_REMOVED_UNARY_BINARY_FUNCTION
.endif

.include <bsd.port.post.mk>
