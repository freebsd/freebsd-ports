# Created by: meitolake@gmail.com
# $FreeBSD$

PORTNAME=	barry
PORTVERSION=	0.12
PORTREVISION=	5
CATEGORIES=	palm
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C++ library for interfacing with the BlackBerry Handheld

LIB_DEPENDS=	boost_thread:${PORTSDIR}/devel/boost-libs

USE_BZIP2=	yes
USE_LDCONFIG=	yes
USES=		pkgconfig
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	OPENSSL_CFLAGS=-I/usr/include \
		OPENSSL_LIBS="-L/lib -lssl -lcrypto"

MAN1=		bcharge.1 bidentify.1 bs11nread.1 btool.1

OPTIONS_DEFINE=	GUI OPENSYNC DOXYGEN DOCS
OPTIONS_DEFAULT=	GUI OPENSYNC
OPENSYNC_DESC=	Build the OpenSync plugin

.include <bsd.port.options.mk>

DEPRECATED=	Broken for more than 6 month
EXPIRATION_DATE=	2013-08-27

CONFIGURE_ENV+=	LIBUSB_LIBS="-lusb" LIBUSB_CFLAGS="-I/usr/include"
BROKEN=		does not configure

.if ${PORT_OPTIONS:MGUI}
LIB_DEPENDS+=	glademm-2.4.1:${PORTSDIR}/devel/libglademm24 \
		tar.0:${PORTSDIR}/devel/libtar
CONFIGURE_ARGS+=	--enable-gui
PLIST_SUB+=	GUI=""
.else
PLIST_SUB+=	GUI="@comment "
.endif

.if ${PORT_OPTIONS:MOPENSYNC}
LIB_DEPENDS+=		opensync.0:${PORTSDIR}/devel/libopensync022
CONFIGURE_ARGS+=	--enable-opensync-plugin
PLIST_SUB+=	OPENSYNC=""
.else
PLIST_SUB+=	OPENSYNC="@comment "
.endif

.if ${PORT_OPTIONS:MDOXYGEN}
BUILD_DEPENDS+=	doxygen:${PORTSDIR}/devel/doxygen
PLIST_SUB+=	DOXYGEN=""
.else
PLIST_SUB+=	DOXYGEN="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|{libdir}/pkgconfig|{prefix}/libdata/pkgconfig|' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's| -Werror||' ${WRKSRC}/opensync-plugin/src/Makefile.in

post-build:
.if ${PORT_OPTIONS:MDOXYGEN}
	@(cd ${WRKSRC}/src && ${LOCALBASE}/bin/doxygen)
.endif

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${CP} -R ${WRKSRC}/doc/ ${DOCSDIR}
.endif

.include <bsd.port.mk>
