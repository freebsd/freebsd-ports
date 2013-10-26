# Created by: Markus Brueffer <markus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ktorrent
DISTVERSION=	4.3.1
PORTREVISION=	2
CATEGORIES=	net-p2p kde
MASTER_SITES=	http://ktorrent.org/downloads/${DISTVERSION}/

MAINTAINER=	makc@FreeBSD.org
COMMENT=	BitTorrent client for KDE

BUILD_DEPENDS=	${LOCALBASE}/include/boost/bind.hpp:${PORTSDIR}/devel/boost-libs
LIB_DEPENDS=	libtag.so:${PORTSDIR}/audio/taglib \
		libgmp.so:${PORTSDIR}/math/gmp \
		libktorrent.so:${PORTSDIR}/net-p2p/libktorrent

USE_BZIP2=	yes
USE_KDE4=	kdelibs kdehier kdeprefix automoc4 pimlibs workspace
USE_QT4=	corelib gui network qt3support qtestlib webkit \
		qmake_build moc_build rcc_build uic_build
USES=		cmake:outsource gettext
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
