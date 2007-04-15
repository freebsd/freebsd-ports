# New ports collection makefile for:	avahi-qt3
# Date created:				12 April 2007
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTREVISION=	0
CATEGORIES=	net
PKGNAMESUFFIX=	-qt3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Qt 3 bindings to the Avahi mDNS system

LIB_DEPENDS=	avahi-common.3:${PORTSDIR}/net/avahi

MASTERDIR=	${.CURDIR}/../avahi
BUILD_WRKSRC=	${WRKSRC}/avahi-qt
INSTALL_WRKSRC=	${BUILD_WRKSRC}
DESCR=		${.CURDIR}/pkg-descr
PLIST=		${.CURDIR}/pkg-plist

AVAHI_SLAVE=	yes

USE_GNOME=	gnomehack gnometarget ltverhack
USE_QT_VER=	3
CONFIGURE_ARGS=	--disable-python \
		--disable-mono \
		--disable-monodoc \
		--disable-gtk \
		--enable-qt3 \
		--disable-qt4 \
		--localstatedir=/var \
		--disable-doxygen-docs \
		--disable-xml-docs \
		--disable-doxygen-dot \
		--with-dbus-system-address=unix:path=/var/run/dbus/system_bus_socket \
		--with-distro=freebsd

post-build:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${GMAKE} \
	    	${MAKE_FLAGS} Makefile ${MAKE_ARGS} avahi-qt3.pc

post-install:
	${MKDIR} ${PREFIX}/libdata/pkgconfig
	${INSTALL_DATA} ${WRKSRC}/avahi-qt3.pc ${PREFIX}/libdata/pkgconfig

.include "${MASTERDIR}/Makefile"
