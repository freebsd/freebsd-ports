# Created by: Tom McLaughlin <tmclaugh@FreeBSD.org>
# $FreeBSD$

PORTREVISION=	0
CATEGORIES=	net dns
PKGNAMESUFFIX=	-sharp

MAINTAINER=	mono@FreeBSD.org
COMMENT=	Mono bindings for Avahi service discovery

LIB_DEPENDS=	libavahi-core.so:net/avahi-app

USES=		mono
MASTERDIR=	${.CURDIR}/../avahi-app
BUILD_WRKSRC=	${WRKSRC}/avahi-sharp
INSTALL_WRKSRC=	${BUILD_WRKSRC}
DESCR=		${.CURDIR}/pkg-descr
PLIST=		${.CURDIR}/pkg-plist

AVAHI_SLAVE=	sharp
AVAHI_PKGCONFIG=avahi-sharp.pc

post-patch:
	@${REINPLACE_CMD} 's|@CLIENT_DLNAME@|libavahi-client.so|g; \
		s|@COMMON_DLNAME@|libavahi-common.so|g; \
		s|@GLIB_DLNAME@|libavahi-glib.so|g' \
		${BUILD_WRKSRC}/avahi-sharp.dll.config.in
	@${CP} ${WRKSRC}/avahi-sharp/avahi-sharp.dll.config.in ${WRKSRC}/avahi-sharp/avahi-sharp.dll.config

.include "${MASTERDIR}/Makefile"
