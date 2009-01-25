# New ports collection makefile for:	ktorrent
# Date created:				Wed Jul 13 11:38:46 CEST 2005
# Whom:					Markus Brueffer <markus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ktorrent
PORTVERSION=	3.1.6
CATEGORIES=	net-p2p kde
MASTER_SITES=	http://ktorrent.org/downloads/${PORTVERSION}/

MAINTAINER=	makc@FreeBSD.org
COMMENT=	BitTorrent client for KDE

LIB_DEPENDS=	gmp.7:${PORTSDIR}/math/libgmp4 \
		qca.2:${PORTSDIR}/devel/qca \
		streamanalyzer.0:${PORTSDIR}/deskutils/strigi

USE_BZIP2=	yes
USE_KDE4=	kdelibs kdehier kdeprefix automoc4
USE_QT_VER=	4
QT_COMPONENTS=	qt3support dbus gui network sql svg xml \
		qmake_build moc_build rcc_build uic_build
USE_CMAKE=	yes
USE_GETTEXT=	yes
USE_LDCONFIG=	yes

.include <bsd.port.mk>
