# Created by: Alex Dupre <ale@FreeBSD.org>
# $FreeBSD$

PORTNAME=	trezord
PORTVERSION=	1.2.1
CATEGORIES=	security
MASTER_SITES=	LOCAL/ale

MAINTAINER=	ale@FreeBSD.org
COMMENT=	TREZOR Communication Daemon aka TREZOR Bridge

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	protoc:devel/protobuf \
		boost-libs>=0:devel/boost-libs
LIB_DEPENDS=	libcurl.so:ftp/curl \
		libjsoncpp.so:devel/jsoncpp \
		libmicrohttpd.so:www/libmicrohttpd

USES=		cmake pkgconfig

USE_RC_SUBR=	${PORTNAME}

CMAKE_ARGS+=	-DJSONCPP_INCLUDE_DIR:STRING="${LOCALBASE}/include/jsoncpp" \
		-DJSONCPP_LIBRARY:STRING="-L${LOCALBASE}/lib -ljsoncpp"

PLIST_FILES=	sbin/${PORTNAME}

post-extract:
	${CP} ${FILESDIR}/usb.hpp ${WRKSRC}/src/
	${CP} ${FILESDIR}/config.proto ${WRKSRC}/src/config/

pre-build:
	cd ${WRKSRC}/src/config && ${LOCALBASE}/bin/protoc \
		-I${LOCALBASE}/include -I. --cpp_out=. config.proto

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}/${PREFIX}/sbin/

.include <bsd.port.mk>
