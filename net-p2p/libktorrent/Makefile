# $FreeBSD$

PORTNAME=	libktorrent
DISTVERSION=	1.3.1
PORTREVISION=	8
CATEGORIES=	net-p2p kde
MASTER_SITES=	http://ktorrent.org/downloads/${DISTVERSION:C,^1,4,:C,-.*,,}/

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Torrent library from KTorrent project

BUILD_DEPENDS=	${LOCALBASE}/include/boost/concept_check.hpp:devel/boost-libs
LIB_DEPENDS=	libgcrypt.so:security/libgcrypt \
		libgmp.so:math/gmp \
		libqca.so:devel/qca

USE_KDE4=	kdelibs automoc4
USE_QT4=	qtestlib_build qmake_build moc_build rcc_build uic_build
USES=		cmake:outsource gettext tar:bzip2
USE_LDCONFIG=	yes

SHLIB_VER=	5.0.1
PLIST_SUB+=	SHLIB_VER=${SHLIB_VER} \
		SHLIB_SHVER=${SHLIB_VER:R:R}

.include <bsd.port.mk>
