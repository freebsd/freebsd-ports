# New ports collection makefile for:	avahi-sharp
# Date Created:				20041011
# Whom:					Tom McLaughlin <tmclaugh@FreeBSD.org>
#
# $FreeBSD$
#   $Id: Makefile,v 1.2 2006/02/15 19:15:40 tmclau02 Exp $
#

PORTREVISION=	0
CATEGORIES=	net dns
PKGNAMESUFFIX=	-sharp

MAINTAINER=	bsd-sharp-list@forge.novell.com
COMMENT=	Mono bindings for Avahi service discovery

LIB_DEPENDS=	avahi-core:${PORTSDIR}/net/avahi
BUILD_DEPENDS=	mono:${PORTSDIR}/lang/mono
RUN_DEPENDS=	mono:${PORTSDIR}/lang/mono

MASTERDIR=	${.CURDIR}/../avahi
BUILD_WRKSRC=	${WRKSRC}/avahi-sharp
INSTALL_WRKSRC=	${BUILD_WRKSRC}
DESCR=		${.CURDIR}/pkg-descr
PLIST=		${.CURDIR}/pkg-plist

AVAHI_SLAVE=	yes

USE_GNOME=	gnomehack gnometarget
CONFIGURE_ARGS= --with-distro=freebsd \
		--with-dbus-system-address=unix:path=/var/run/dbus \
		--disable-qt3 \
		--disable-qt4 \
		--disable-python \
		--enable-mono \
		--disable-monodoc \
		--disable-doxygen-doc \
		--disable-doxygen-dot \
		--localstatedir=/var

post-patch:
	@${REINPLACE_CMD} 's|@CLIENT_DLNAME@|libavahi-client.so|g; \
		s|@COMMON_DLNAME@|libavahi-common.so|g; \
		s|@GLIB_DLNAME@|libavahi-glib.so|g' \
		${BUILD_WRKSRC}/avahi-sharp.dll.config.in
	@${REINPLACE_CMD} 's|@prefix@|${PREFIX}|g; \
		s|@libdir@|$${prefix}/lib|g; \
		s|@PACKAGE_VERSION@|${PORTVERSION}|g' \
		${WRKSRC}/avahi-sharp.pc.in
	@${CP} ${WRKSRC}/avahi-sharp.pc.in ${WRKSRC}/avahi-sharp.pc

post-install:
	${INSTALL_DATA} ${WRKSRC}/avahi-sharp.pc  ${PREFIX}/libdata/pkgconfig/

.include "${.CURDIR}/../../lang/mono/bsd.mono.mk"
.include "${MASTERDIR}/Makefile"
