# New ports collection makefile for:	libktorrent
# Date created:		2010-05-05
# Whom:			Max Brazhnikov <makc@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libktorrent
DISTVERSION=	1.2.1-2
CATEGORIES=	net-p2p kde
MASTER_SITES=	http://ktorrent.org/downloads/${DISTVERSION:C,^1,4,:C,-.*,,}/

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Torrent library split from KTorrent

LIB_DEPENDS=	gmp.10:${PORTSDIR}/math/gmp \
		qca.2:${PORTSDIR}/devel/qca \
		boost_thread.4:${PORTSDIR}/devel/boost-libs

USE_BZIP2=	yes
USE_KDE4=	kdelibs kdehier kdeprefix automoc4
USE_QT4=	qmake_build moc_build rcc_build uic_build
USE_CMAKE=	yes
USE_GETTEXT=	yes
USE_LDCONFIG=	yes
MAKE_JOBS_SAFE=	yes

SHLIB_VER=	4.0.1
PLIST_SUB+=	SHLIB_VER=${SHLIB_VER} \
		SHLIB_SHVER=${SHLIB_VER:R:R}

.include <bsd.port.mk>
