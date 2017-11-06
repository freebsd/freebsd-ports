# Created by: David Barksdale <amatus@gnu.org>
# $FreeBSD$

PORTNAME=	libmicrohttpd
PORTVERSION=	0.9.52
CATEGORIES=	www
MASTER_SITES=	GNU

MAINTAINER=	gaod@hychen.org
COMMENT=	C library for embedding HTTP server functionality

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USES=		cpe libtool pathfix
USE_LDCONFIG=	yes

CPE_VENDOR=	gnu

OPTIONS_DEFINE=	GNUTLS

GNUTLS_LIB_DEPENDS=	libgcrypt.so:security/libgcrypt \
			libgnutls.so:security/gnutls
GNUTLS_CONFIGURE_WITH=	libgcrypt-prefix=${LOCALBASE} gnutls=${LOCALBASE}
GNUTLS_CONFIGURE_ENABLE=https

INFO=		libmicrohttpd libmicrohttpd-tutorial

PLIST_FILES=	include/microhttpd.h \
		lib/libmicrohttpd.a \
		lib/libmicrohttpd.so \
		lib/libmicrohttpd.so.12 \
		lib/libmicrohttpd.so.12.40.0 \
		libdata/pkgconfig/libmicrohttpd.pc \
		man/man3/libmicrohttpd.3.gz

post-patch:
	@${REINPLACE_CMD} -e 's|bin_PROGRAMS =|noinst_PROGRAMS +=|' \
		${WRKSRC}/src/examples/Makefile.in

.include <bsd.port.mk>
