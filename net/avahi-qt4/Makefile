# Created by: Michael Johnson <ahze@FreeBSD.org
# $FreeBSD$

PORTREVISION=	0
CATEGORIES=	net
PKGNAMESUFFIX=	-qt4

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Qt 4 bindings to the Avahi mDNS system

DEPRECATED=		Qt4 has been EOL since december 2015
EXPIRATION_DATE=	2019-03-15

LIB_DEPENDS=	libavahi-common.so:net/avahi-app

MASTERDIR=	${.CURDIR}/../avahi-app
BUILD_WRKSRC=	${WRKSRC}/avahi-qt
INSTALL_WRKSRC=	${BUILD_WRKSRC}
DESCR=		${.CURDIR}/pkg-descr
PLIST=		${.CURDIR}/pkg-plist

AVAHI_SLAVE=	qt4
USES=		qt:4
USE_QT=		corelib moc_build
AVAHI_PKGCONFIG=avahi-qt4.pc

.include "${MASTERDIR}/Makefile"
