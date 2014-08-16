# Created by: Aleksander Fafula <alex@BSDGuru.org>
# $FreeBSD$

PORTNAME=	libgadu
DISTVERSION=	1.12.0
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	polish net-im

MAINTAINER=	pawel@FreeBSD.org
COMMENT=	Instant messaging library for Gadu-Gadu protocol

LICENSE=	LGPL21

LIB_DEPENDS=	libprotobuf-c.so:${PORTSDIR}/devel/protobuf-c

CONFLICTS=	pl-ekg-1.[0-6]*

USE_GITHUB=	yes
GH_ACCOUNT=	wojtekka
GH_COMMIT=	ff39edb	

USES=		gmake libtool pkgconfig tar:bzip2
USE_AUTOTOOLS=	aclocal autoconf autoheader automake libtoolize
ACLOCAL_ARGS=	-I m4
AUTOMAKE_ARGS=	--add-missing
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-shared --disable-static --with-pthread \
		--disable-tests --without-gnutls
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_FILES=	include/libgadu.h \
		lib/libgadu.so \
		lib/libgadu.so.3 \
		lib/libgadu.so.3.13.0 \
		libdata/pkgconfig/libgadu.pc

OPTIONS_DEFINE=	OPENSSL
OPTIONS_DEFAULT=OPENSSL

OPENSSL_CONFIGURE_WITH=	openssl
OPENSSL_USE=		OPENSSL=yes

.include <bsd.port.pre.mk>

post-configure:
	@${REINPLACE_CMD} '/^sed/ s|^|#|' ${WRKSRC}/protobufgen.sh
	@${REINPLACE_CMD} '/^pkgconfigdir/ s|libdir)|prefix)/libdata|' \
		${WRKSRC}/pkgconfig/Makefile

pre-install:
# OpenSSL from base system lacks .pc file for pkgconfig
.if ${PORT_OPTIONS:MOPENSSL}
	@${REINPLACE_CMD} -e 's|openssl| |g' ${WRKSRC}/pkgconfig/libgadu.pc
.endif

.include <bsd.port.post.mk>
