PORTNAME=	libktorrent
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	net-p2p kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Torrent library from KTorrent project
WWW=		https://ktorrent.org/

BUILD_DEPENDS=	${LOCALBASE}/include/boost/concept_check.hpp:devel/boost-libs
LIB_DEPENDS=	libgcrypt.so:security/libgcrypt \
		libgmp.so:math/gmp

USES=		cmake compiler:c++11-lang gettext kde:5 qca qt:5 tar:xz xorg
USE_KDE=	archive completion config coreaddons crash i18n \
		jobwidgets kio service solid widgetsaddons windowsystem \
		ecm:build
USE_QT=		concurrent core dbus gui network widgets xml \
		buildtools:build qmake:build testlib:build
USE_XORG=	x11

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
