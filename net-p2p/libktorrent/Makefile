# $FreeBSD$

PORTNAME=	libktorrent
DISTVERSION=	1.3.1
PORTREVISION=	6
CATEGORIES=	net-p2p kde
MASTER_SITES=	http://ktorrent.org/downloads/${DISTVERSION:C,^1,4,:C,-.*,,}/

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Torrent library from KTorrent project

BUILD_DEPENDS=	${LOCALBASE}/include/boost/concept_check.hpp:${PORTSDIR}/devel/boost-libs
LIB_DEPENDS=	libgcrypt.so:${PORTSDIR}/security/libgcrypt \
		libgmp.so:${PORTSDIR}/math/gmp \
		libqca.so:${PORTSDIR}/devel/qca

USE_KDE4=	kdelibs kdehier kdeprefix automoc4
USE_QT4=	qtestlib_build qmake_build moc_build rcc_build uic_build
USES=		cmake:outsource gettext tar:bzip2
USE_LDCONFIG=	yes

SHLIB_VER=	5.0.1
PLIST_SUB+=	SHLIB_VER=${SHLIB_VER} \
		SHLIB_SHVER=${SHLIB_VER:R:R}

.include <bsd.port.mk>
