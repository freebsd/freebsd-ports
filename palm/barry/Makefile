# New ports collection makefile for:	barry
# Date created:				20 Jul 2008
# Whom:					meitolake@gmail.com
#
# $FreeBSD$
#

PORTNAME=	barry
PORTVERSION=	0.12
PORTREVISION=	1
CATEGORIES=	palm
MASTER_SITES=	SF

MAINTAINER=	meitolake@gmail.com
COMMENT=	C++ library for interfacing with the BlackBerry Handheld

LIB_DEPENDS=	boost_thread.4:${PORTSDIR}/devel/boost-libs

USE_BZIP2=	yes
USE_LDCONFIG=	yes
USE_GNOME=	pkgconfig
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	OPENSSL_CFLAGS=-I/usr/include \
		OPENSSL_LIBS="-L/lib -lssl -lcrypto"

MAN1=		bcharge.1 bidentify.1 bs11nread.1 btool.1

OPTIONS=	GUI "Build the GUI" On \
		OPENSYNC "Build the OpenSync plugin" On \
		DOXYGEN "Build API documentation" Off

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 800069
LIB_DEPENDS+=	usb-0.1.8:${PORTSDIR}/devel/libusb
.else
CONFIGURE_ENV+=	LIBUSB_LIBS="-lusb" LIBUSB_CFLAGS="-I/usr/include"
BROKEN=		does not configure
.endif

.if defined(WITH_GUI)
LIB_DEPENDS+=	glademm-2.4.1:${PORTSDIR}/devel/libglademm24 \
		tar.0:${PORTSDIR}/devel/libtar
CONFIGURE_ARGS+=	--enable-gui
PLIST_SUB+=	GUI=""
.else
PLIST_SUB+=	GUI="@comment "
.endif

.if defined(WITH_OPENSYNC)
LIB_DEPENDS+=		opensync.0:${PORTSDIR}/devel/libopensync022
CONFIGURE_ARGS+=	--enable-opensync-plugin
PLIST_SUB+=	OPENSYNC=""
.else
PLIST_SUB+=	OPENSYNC="@comment "
.endif

.if defined(WITH_DOXYGEN)
BUILD_DEPENDS+=	doxygen:${PORTSDIR}/devel/doxygen
PLIST_SUB+=	DOXYGEN=""
.else
PLIST_SUB+=	DOXYGEN="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|{libdir}/pkgconfig|{prefix}/libdata/pkgconfig|' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's| -Werror||' ${WRKSRC}/opensync-plugin/src/Makefile.in

post-build:
.if defined(WITH_DOXYGEN)
	@(cd ${WRKSRC}/src && ${LOCALBASE}/bin/doxygen)
.endif

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${CP} -R ${WRKSRC}/doc/ ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
