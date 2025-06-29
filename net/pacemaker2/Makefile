PORTVERSION=		2.1.7
PORTREVISION=		5
PKGNAMESUFFIX=		2

WWW=		https://www.clusterlabs.org/pacemaker/

.include "${.CURDIR}/Makefile.common"

CONFIGURE_ARGS+=	--with-noarch-pkgconfigdir=${PREFIX}/libdata/pkgconfig

LIB_DEPENDS+=		libffi.so:devel/libffi \
	libgmp.so:math/gmp \
	libhogweed.so:security/nettle \
	libidn2.so:dns/libidn2 \
	libnettle.so:security/nettle \
	libp11-kit.so:security/p11-kit \
	libpcre.so:devel/pcre \
	libtasn1.so:security/libtasn1 \
	libunistring.so:devel/libunistring

USES+=	gettext

SHEBANG_FILES+=	agents/ocf/*

post-patch: post-patch-common

post-install:
	${RM} ${STAGEDIR}/${PREFIX}/etc/rc.d/pacemaker_remote

.include <bsd.port.mk>
