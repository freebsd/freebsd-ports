# Created by: Markus Brueffer <markus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ktorrent
DISTVERSION=	4.3.1
PORTREVISION=	17
CATEGORIES=	net-p2p kde
MASTER_SITES=	http://ktorrent.org/downloads/${DISTVERSION}/
PKGNAMESUFFIX=	-kde4

MAINTAINER=	kde@FreeBSD.org
COMMENT=	BitTorrent client for KDE

DEPRECATED=	KDE4 is EOL upstream
EXPIRATION_DATE=	2018-12-31

BUILD_DEPENDS=	${LOCALBASE}/include/boost/bind.hpp:devel/boost-libs
LIB_DEPENDS=	libtag.so:audio/taglib \
		libgmp.so:math/gmp \
		libktorrent.so:net-p2p/libktorrent-kde4

USES=		cmake:outsource gettext kde:4 qt:4 tar:bzip2
USE_KDE=	kdelibs automoc4 pimlibs workspace
USE_QT=		corelib gui network qt3support qtestlib webkit \
		qmake_build moc_build rcc_build uic_build
USE_LDCONFIG=	yes

CONFLICTS_BUILD=	ktorrent-2*

SHLIB_VER=	15.0.0
PLIST_SUB+=	SHLIB_VER=${SHLIB_VER} \
		SHLIB_SHVER=${SHLIB_VER:R:R}

CMAKE_ARGS+=	-DENABLE_KIO_MAGNET=1

post-patch:
	${REINPLACE_CMD} -e 's,ktorrent,$${LIBKTORRENT_LIBRARIES},' \
		${WRKSRC}/plugins/ipfilter/tests/CMakeLists.txt

.include <bsd.port.mk>
