# New ports collection makefile for:	avahi-qt4
# Date created:				26 October 2007
# Whom:					Michael Johnson <ahze@FreeBSD.org
#
# $FreeBSD$
#

PORTREVISION=	0
CATEGORIES=	net
PKGNAMESUFFIX=	-qt4

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Qt 4 bindings to the Avahi mDNS system

LIB_DEPENDS=	avahi-common.3:${PORTSDIR}/net/avahi-app

MASTERDIR=	${.CURDIR}/../avahi-app
BUILD_WRKSRC=	${WRKSRC}/avahi-qt
INSTALL_WRKSRC=	${BUILD_WRKSRC}
DESCR=		${.CURDIR}/pkg-descr
PLIST=		${.CURDIR}/pkg-plist

AVAHI_SLAVE=	qt4
USE_GNOME=	gnomehack gnometarget ltverhack intltool
USE_QT_VER=	4
QT_COMPONENTS=	corelib moc_build
AVAHI_PKGCONFIG=	avahi-qt4.pc

.include "${MASTERDIR}/Makefile"
