# $FreeBSD$

PORTNAME=	ktorrent
DISTVERSION=	5.1.2
PORTREVISION=	1
CATEGORIES=	net-p2p kde
MASTER_SITES=	KDE/stable/${PORTNAME}/${DISTVERSION}/

# Since libktorrent is released with ktorrent, it lives in a
# strange download directory; keep this in-sync with net-p2p/libktorrent.

MAINTAINER=	kde@FreeBSD.org
COMMENT=	BitTorrent client for KDE

USES=		cmake compiler:c++11-lang gettext kde:5 qt:5 tar:xz

LIB_DEPENDS=	libKF5Torrent.so:net-p2p/libktorrent \
		libgcrypt.so:security/libgcrypt \
		libgmp.so:math/gmp \
		libtag.so:audio/taglib
USE_KDE=	archive auth bookmarks codecs completion config configwidgets \
		coreaddons crash dbusaddons dnssd i18n iconthemes itemviews \
		jobwidgets kcmutils kdewebkit kio kross notifications \
		notifyconfig parts plotting service \
		solid sonnet syndication textwidgets widgetsaddons \
		windowsystem xmlgui
USE_QT=		concurrent core dbus gui network phonon4 script webkit widgets xml \
		buildtools_build qmake_build

OPTIONS_DEFINE=	WORKSPACE
OPTIONS_DEFAULT=	WORKSPACE
OPTIONS_SUB=	yes

WORKSPACE_USE=	KDE=plasma-workspace
WORKSPACE_DESC=	Shutdown on completion support
WORKSPACE_CMAKE_BOOL_OFF=	CMAKE_DISABLE_FIND_PACKAGE_LibKWorkspace

.include <bsd.port.mk>
