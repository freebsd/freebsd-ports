# $FreeBSD$

# TODO: once plasma5 ports are in, re-add dependency on workspace.

PORTNAME=	ktorrent
DISTVERSION=	5.1.1
CATEGORIES=	net-p2p kde
MASTER_SITES=	KDE/stable/${PORTNAME}/${DISTVERSION}/

MAINTAINER=	kde@FreeBSD.org
COMMENT=	BitTorrent client for KDE

USES=		cmake gettext kde:5 qt:5 tar:xz

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
USE_QT=		core dbus gui network phonon4 script webkit widgets xml \
		buildtools_build qmake_build

.include <bsd.port.mk>
