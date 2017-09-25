# $FreeBSD$

PORTNAME=	libktorrent
DISTVERSION=	1.3.1
PORTREVISION=	13
CATEGORIES=	net-p2p kde
MASTER_SITES=	http://ktorrent.org/downloads/${DISTVERSION:C,^1,4,:C,-.*,,}/

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Torrent library from KTorrent project

BUILD_DEPENDS=	${LOCALBASE}/include/boost/concept_check.hpp:devel/boost-libs
LIB_DEPENDS=	libgcrypt.so:security/libgcrypt \
		libgmp.so:math/gmp \
		libqca.so:devel/qca

USES=		cmake:outsource gettext kde:4 tar:bzip2
USE_KDE=	kdelibs automoc4
USE_QT4=	qtestlib_build qmake_build moc_build rcc_build uic_build
USE_LDCONFIG=	yes

SHLIB_VER=	5.0.1
PLIST_SUB+=	SHLIB_VER=${SHLIB_VER} \
		SHLIB_SHVER=${SHLIB_VER:R:R}

.include <bsd.port.mk>
