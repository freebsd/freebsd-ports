PORTNAME=	ktorrent
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	net-p2p kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	BitTorrent client for KDE
WWW=		https://kde.org/applications/en/internet/org.kde.ktorrent

CONFLICTS_BUILD=	libtorrent

BUILD_DEPENDS=	${LOCALBASE}/include/boost/concept_check.hpp:devel/boost-libs
LIB_DEPENDS=	libKTorrent6.so:net-p2p/libktorrent \
		libgcrypt.so:security/libgcrypt \
		libgmp.so:math/gmp \
		libtag.so:audio/taglib

USES=		cmake compiler:c++11-lang desktop-file-utils gettext gl kde:6 \
		qt:6 tar:xz xorg
USE_GL=		opengl
USE_KDE=	archive auth bookmarks codecs colorscheme completion config \
		configwidgets coreaddons crash dbusaddons dnssd globalaccel \
		guiaddons i18n iconthemes itemviews jobwidgets kcmutils kio \
		notifications notifyconfig parts plotting service solid \
		sonnet statusnotifieritem syndication textwidgets \
		widgetsaddons windowsystem xmlgui \
		ecm:build
USE_QT=		base declarative multimedia
USE_XORG=	x11

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

.if ${ARCH} == aarch64 || ${ARCH} == amd64 || ${ARCH} == i386 || ${ARCH} == powerpc64le
PLIST_SUB+=	WEBENGINE=""
USE_QT+=	5compat positioning webchannel webengine
.else
PLIST_SUB+=	WEBENGINE="@comment "
.endif

.include <bsd.port.mk>
