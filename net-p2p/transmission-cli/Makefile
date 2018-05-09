# $FreeBSD$

PORTNAME=	transmission
PORTVERSION=	2.93
PORTREVISION?=	1
CATEGORIES?=	net-p2p
MASTER_SITES=	https://github.com/transmission/transmission-releases/raw/master/ \
		http://transmission.cachefly.net/
PKGNAMESUFFIX?=	-cli

MAINTAINER?=	crees@FreeBSD.org
COMMENT?=	Lightweight CLI (command line) BitTorrent client and utilities

SLAVEPORT?=	cli

LICENSE=	GPLv2+
.if ${SLAVEPORT} == cli
LICENSE+=	MIT
LICENSE_COMB=	multi
.endif
LICENSE_FILE=	${WRKSRC}/COPYING

USES+=		cpe tar:xz
CPE_VENDOR=	transmissionbt

CONFLICTS_INSTALL=	${PORTNAME}${PKGNAMESUFFIX}-2.5*

EXTRACT_AFTER_ARGS=--no-same-owner --no-same-permissions --exclude third-party

.if ${SLAVEPORT} != web
LIB_DEPENDS?=	${GEN_LIB_DEPENDS}

# General dependencies
GEN_LIB_DEPENDS=libb64.so:converters/libb64 \
		libcurl.so:ftp/curl \
		libdht.so:devel/jech-dht \
		libminiupnpc.so:net/miniupnpc \
		libnatpmp.so:net/libnatpmp \
		libutp.so:net/libutp \
		libevent.so:devel/libevent
GEN_RUN_DEPENDS=${LOCALBASE}/share/transmission/web/index.html:www/transmission-web

# This is master port of transmission-*, so don't override USES definition
USES+=		gmake iconv libtool localbase pkgconfig
GNU_CONFIGURE=	yes
LIBS+=		${ICONV_LIB}
CONFIGURE_ENV=	${ICONV_LIB:C@.+@ac_cv_func_iconv=yes@}
CONFIGURE_ARGS=	--without-inotify \
		--enable-external-b64 \
		--enable-external-dht \
		--enable-external-natpmp \
		${EXTRA_CONF_ARGS}

EXTRA_CONF_ARGS?=--enable-cli \
		 --disable-daemon \
		 --without-gtk \
		 --disable-mac \
		 --disable-nls

EXTRA_PATCHES=	${PATCHDIR}/disable-web

OPTIONS_DEFINE+=	DOCS LITE
OPTIONS_DEFAULT+=	OPENSSL
OPTIONS_SINGLE+=	SSL
OPTIONS_SINGLE_SSL+=	OPENSSL WOLFSSL

LITE_CONFIGURE_ENABLE=	lightweight

OPENSSL_USES=		ssl
OPENSSL_CONFIGURE_ENV=	OPENSSL_CFLAGS="-I${OPENSSLINC}" \
			OPENSSL_LIBS="-L${OPENSSLLIB} -lcrypto"
OPENSSL_CONFIGURE_ON=	--with-crypto=openssl

WOLFSSL_LIB_DEPENDS=	libwolfssl.so:security/wolfssl
WOLFSSL_CONFIGURE_ON=	--with-crypto=cyassl
WOLFSSL_BROKEN=		Requires security/wolfssl built with --enable-arc4
.endif

DOCS=		AUTHORS NEWS README
DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}${PKGNAMESUFFIX}

general-patch:
	@${FIND} ${WRKSRC} -name Makefile.in | ${XARGS} ${REINPLACE_CMD} -e \
		's|noinst_PROGRAMS = |noinst_PROGRAMS = #|g'
.if ${SLAVEPORT} != gtk
	@${REINPLACE_CMD} -e '/#define DISABLE_GETTEXT/s,/\* \(.*\) \*/,\1,' \
		${WRKSRC}/libtransmission/utils.h
.endif
	@${REINPLACE_CMD} -e \
		's|rt_clock_gettime=yes|rt_clock_gettime=no|g ; \
		s|" == "|" = "|g' \
			${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|doc \\| \\|g' \
		${WRKSRC}/Makefile.in
.if ${SLAVEPORT} != cli
	@${REINPLACE_CMD} -e 's|utils \\|\\|g' \
		${WRKSRC}/Makefile.in
.endif
# Don't conflict with patches but force system libraries
	@${REINPLACE_CMD} -e 's|third-party \\|\\|g' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} \
		-e 's|third-party/[^ ]*Makefile||g' \
		${WRKSRC}/configure

post-patch: general-patch

general-install:
.if ${SLAVEPORT} != web
	(cd ${WRKSRC} && ${COPYTREE_SHARE} \
		"${DOCS}" ${STAGEDIR}${DOCSDIR})
.endif

post-install: general-install

.include <bsd.port.mk>
