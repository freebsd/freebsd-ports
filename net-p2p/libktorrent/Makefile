# $FreeBSD$

PORTNAME=	libktorrent
DISTVERSION=	2.2.0
CATEGORIES=	net-p2p kde
MASTER_SITES=	KDE/stable/ktorrent/5.2.0/

# Since libktorrent is released with ktorrent, it lives in a
# strange download directory; keep this in-sync with net-p2p/ktorrent.

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Torrent library from KTorrent project

BUILD_DEPENDS=	${LOCALBASE}/include/boost/concept_check.hpp:devel/boost-libs

LIB_DEPENDS=	libgcrypt.so:security/libgcrypt \
		libgmp.so:math/gmp

USES=		cmake compiler:c++11-lang gettext kde:5 qca qt:5 tar:xz
USE_KDE=	archive completion config coreaddons crash ecm i18n \
		jobwidgets kio service solid widgetsaddons
USE_QT=		core gui network testlib xml \
		buildtools_build qmake_build

.include <bsd.port.mk>
