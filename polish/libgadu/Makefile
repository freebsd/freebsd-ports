# Created by: Aleksander Fafula <alex@BSDGuru.org>
# $FreeBSD$

PORTNAME=	libgadu
PORTVERSION=	1.12.2
PORTEPOCH=	1
CATEGORIES=	polish net-im

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Instant messaging library for Gadu-Gadu protocol

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libprotobuf-c.so:devel/protobuf-c \
		libgnutls.so:security/gnutls

CONFLICTS=	pl-ekg-1.[0-6]*

USE_GITHUB=	yes
GH_ACCOUNT=	wojtekka

USES=		autoreconf gmake libtool localbase pathfix pkgconfig
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-shared --disable-static --with-pthread \
		--disable-tests
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

PLIST_FILES=	include/libgadu.h \
		lib/libgadu.so \
		lib/libgadu.so.3 \
		lib/libgadu.so.3.13.0 \
		libdata/pkgconfig/libgadu.pc

.include <bsd.port.mk>
