# New ports collection Makefile for:	kdeutils
# Date created:				2008-01-31
# Whom:					Martin Wilke <miwi@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	kdeutils
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	misc kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/${PORTVERSION}/src
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Utilities for the KDE4 integrated X11 Desktop

LIB_DEPENDS=    gmp.7:${PORTSDIR}/math/libgmp4 \
		netsnmp:${PORTSDIR}/net-mgmt/net-snmp \
		qimageblitz.4:${PORTSDIR}/x11/qimageblitz \
		zip.1:${PORTSDIR}/archivers/libzip
RUN_DEPENDS=    gpg:${PORTSDIR}/security/gnupg

LATEST_LINK=	${PORTNAME}4

USE_BZIP2=	yes
USE_QT_VER=	4
KDE4_BUILDENV= yes
USE_KDE4=	kdelibs pimlibs workspace kdeprefix kdehier automoc4
QT_COMPONENTS=	network gui moc rcc uic porting xml

post-extract:
	${MKDIR} ${WRKSRC}

.include <bsd.port.mk>
