# New ports collection makefile for:	libktorrent
# Date created:		2010-05-05
# Whom:			Max Brazhnikov <makc@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libktorrent
DISTVERSION=	1.1.2
PORTREVISION=	1
CATEGORIES=	net-p2p kde
MASTER_SITES=	http://ktorrent.org/downloads/${DISTVERSION:S,^1,4,}/

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Torrent library split from KTorrent

LIB_DEPENDS=	gmp.10:${PORTSDIR}/math/gmp \
		qca.2:${PORTSDIR}/devel/qca \
		boost_thread.4:${PORTSDIR}/devel/boost-libs

USE_BZIP2=	yes
USE_KDE4=	kdelibs kdehier kdeprefix automoc4
USE_QT_VER=	4
QT_COMPONENTS=	qmake_build moc_build rcc_build uic_build
USE_CMAKE=	yes
USE_GETTEXT=	yes
USE_LDCONFIG=	yes
MAKE_JOBS_SAFE=	yes

.include <bsd.port.mk>
