# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$

PORTREVISION=	0
CATEGORIES=	net
PKGNAMESUFFIX=	-gtk3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Gtk+ 3 library to the Avahi mDNS system

LIB_DEPENDS=	libavahi-common.so:net/avahi-app \
		libgdbm.so:databases/gdbm
RUN_DEPENDS=	avahi-header>=0.7:net/avahi-header

MASTERDIR=	${.CURDIR}/../avahi-app
BUILD_WRKSRC=	${WRKSRC}/avahi-ui
INSTALL_WRKSRC=	${BUILD_WRKSRC}
DESCR=		${.CURDIR}/pkg-descr
PLIST=		${.CURDIR}/pkg-plist

AVAHI_SLAVE=	gtk3
AVAHI_PKGCONFIG=avahi-ui-gtk3.pc

USE_GNOME+=	cairo gdkpixbuf2 gtk30

do-build:
	@(cd ${WRKSRC}/avahi-common; ${MAKE_CMD})
	@(cd ${WRKSRC}/avahi-client; ${MAKE_CMD})
	@(cd ${WRKSRC}/avahi-glib; ${MAKE_CMD})
	@(cd ${WRKSRC}/avahi-ui; ${MAKE_CMD} libavahi-ui-gtk3.la)

do-install:
	@(cd ${WRKSRC}/avahi-ui; ${MAKE_CMD} ${MAKE_ARGS} install-libLTLIBRARIES)

.include "${MASTERDIR}/Makefile"
