PORTNAME=	messagelib
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
PORTREVISION=	1
CATEGORIES=	net kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Library for handling messages
WWW=		https://invent.kde.org/pim/messagelib

LICENSE=	LGPL21

LIB_DEPENDS=	libgpgmepp.so:security/gpgmepp \
		libqgpgmeqt6.so:security/qgpgme@qt6

USES=		cmake compiler cpe gettext-tools inotify kde:6 qt:6 \
		ssl tar:xz
CPE_VENDOR=	kde
# KDE Frameworks
USE_KDE=	archive calendarcore codecs colorscheme completion \
		contacts coreaddons guiaddons i18n iconthemes itemviews \
		jobwidgets kio ktextaddons mime newstuff notifications \
		sonnet syntaxhighlighting texttemplate textwidgets \
		widgetsaddons xmlgui \
		ecm:build
# KDE PIM
USE_KDE+=	akonadi akonadicontacts akonadimime akonadisearch \
		grantleetheme gravatar identitymanagement libkdepim \
		libkleo mailtransport mbox pimcommon pimtextedit
USE_QT=		base declarative webengine
USE_LDCONFIG=	yes

.include <bsd.port.pre.mk>

.if ${COMPILER_TYPE} == clang
CXXFLAGS+=	-D_LIBCPP_ENABLE_CXX17_REMOVED_UNARY_BINARY_FUNCTION
.endif

.include <bsd.port.post.mk>
