PORTNAME=	libktorrent
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	net-p2p kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Torrent library from KTorrent project
WWW=		https://ktorrent.org/

BUILD_DEPENDS=	${LOCALBASE}/include/boost/concept_check.hpp:devel/boost-libs
LIB_DEPENDS=	libgcrypt.so:security/libgcrypt \
		libgmp.so:math/gmp \
		libqca-qt6.so:devel/qca@qt6

USES=		cmake compiler:c++11-lang gettext kde:6 qt:6 tar:xz xorg
USE_KDE=	archive completion config coreaddons crash i18n jobwidgets kio \
		service solid widgetsaddons windowsystem \
		ecm:build
USE_QT=		base
USE_XORG=	x11

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
