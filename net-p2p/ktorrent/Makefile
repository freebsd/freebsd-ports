# New ports collection makefile for:	ktorrent
# Date created:				Wed Jul 13 11:38:46 CEST 2005
# Whom:					Markus Brueffer <markus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ktorrent
DISTVERSION=	4.1.2
PORTREVISION=	1
CATEGORIES=	net-p2p kde
MASTER_SITES=	http://ktorrent.org/downloads/${DISTVERSION}/

MAINTAINER=	makc@FreeBSD.org
COMMENT=	BitTorrent client for KDE

LIB_DEPENDS=	gmp.10:${PORTSDIR}/math/gmp \
		qca.2:${PORTSDIR}/devel/qca \
		tag.1:${PORTSDIR}/audio/taglib \
		ktorrent.3:${PORTSDIR}/net-p2p/libktorrent

USE_BZIP2=	yes
USE_KDE4=	kdelibs kdehier kdeprefix automoc4 pimlibs workspace
USE_QT_VER=	4
QT_COMPONENTS=	qmake_build moc_build rcc_build uic_build
USE_CMAKE=	yes
USE_GETTEXT=	yes
USE_LDCONFIG=	yes
MAKE_JOBS_SAFE=	yes

.if exists(${LOCALBASE}/lib/libktorrent-2.2.8.so)
IGNORE=	fails to build with net-p2p/ktorrent2 installed. Deinstall it first
.endif

.include <bsd.port.mk>
