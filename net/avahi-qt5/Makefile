# Created by: Michael Johnson <ahze@FreeBSD.org
# $FreeBSD$

PORTREVISION=	0
CATEGORIES=	net
PKGNAMESUFFIX=	-qt5

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Qt 5 bindings to the Avahi mDNS system

LIB_DEPENDS=	libavahi-common.so:net/avahi-app

MASTERDIR=	${.CURDIR}/../avahi-app
BUILD_WRKSRC=	${WRKSRC}/avahi-qt
INSTALL_WRKSRC=	${BUILD_WRKSRC}
DESCR=		${.CURDIR}/pkg-descr
PLIST=		${.CURDIR}/pkg-plist

AVAHI_SLAVE=	qt5
USES=		qt:5
USE_QT=		core buildtools_build
AVAHI_PKGCONFIG=avahi-qt5.pc

.include "${MASTERDIR}/Makefile"
