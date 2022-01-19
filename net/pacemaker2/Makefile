# Created by: David Shane Holden <dpejesh@yahoo.com>

PORTVERSION=		2.1.2
PKGNAMESUFFIX=		2

.include "${.CURDIR}/../pacemaker1/Makefile.common"

CONFIGURE_ARGS+=	--with-noarch-pkgconfigdir=${PREFIX}/libdata/pkgconfig

CONFLICTS+=		pacemaker1

LIB_DEPENDS+=		libffi.so:devel/libffi \
	libgmp.so:math/gmp \
	libhogweed.so:security/nettle \
	libidn2.so:dns/libidn2 \
	libnettle.so:security/nettle \
	libp11-kit.so:security/p11-kit \
	libpcre.so:devel/pcre \
	libtasn1.so:security/libtasn1 \
	libunistring.so:devel/libunistring

post-patch: post-patch-common

post-install:
	${RM} ${STAGEDIR}/${PREFIX}/etc/rc.d/pacemaker_remote

.include <bsd.port.mk>
