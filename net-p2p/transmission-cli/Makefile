# $FreeBSD$

PORTNAME=	transmission
PORTVERSION=	2.84
PORTREVISION?=	3
CATEGORIES?=	net-p2p
#MASTER_SITES=	http://download.m0k.org/${PORTNAME}/files/
MASTER_SITES=	http://transmission.cachefly.net/
PKGNAMESUFFIX?=	-cli

MAINTAINER?=	jbeich@FreeBSD.org
COMMENT?=	Lightweight CLI (command line) BitTorrent client and utilities

SLAVEPORT?=	cli

LICENSE=	GPLv2
.if ${SLAVEPORT} == cli
LICENSE+=	MIT
LICENSE_COMB=	multi
.endif
LICENSE_FILE=	${WRKSRC}/COPYING

USES+=		cpe tar:xz
CPE_VENDOR=	transmissionbt

CONFLICTS_INSTALL=	${PORTNAME}${PKGNAMESUFFIX}-2.5*

OPTIONS_DEFINE=	LITE DOCS
EXTRACT_AFTER_ARGS=--no-same-owner --no-same-permissions --exclude third-party

.if ${SLAVEPORT} != web
LIB_DEPENDS?=	${GEN_LIB_DEPENDS}

# General dependencies
GEN_LIB_DEPENDS=libcurl.so:${PORTSDIR}/ftp/curl \
		libdht.so:${PORTSDIR}/devel/jech-dht \
		libminiupnpc.so:${PORTSDIR}/net/miniupnpc \
		libnatpmp.so:${PORTSDIR}/net/libnatpmp \
		libutp.so:${PORTSDIR}/net/libutp \
		libevent.so:${PORTSDIR}/devel/libevent2
GEN_RUN_DEPENDS=${LOCALBASE}/share/transmission/web/index.html:${PORTSDIR}/www/transmission-web

# This is master port of transmission-*, so don't override USES definition
USES+=		gmake iconv libtool localbase pkgconfig
USE_OPENSSL=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-DWITH_UTP=1
LIBS+=		${ICONV_LIB}
CONFIGURE_ARGS=--with-zlib=/usr \
		 --without-inotify \
		 --disable-utp \
		 --enable-external-natpmp \
		${EXTRA_CONF_ARGS}
CONFIGURE_ENV=	OPENSSL_CFLAGS="-I${OPENSSLINC}" \
		OPENSSL_LIBS="-L${OPENSSLLIB} -lcrypto" \
		DHT_CFLAGS=" " \
		DHT_LIBS="-ldht" \
		LIBUTP_CFLAGS=" " \
		LIBUTP_LIBS="-lutp" \
		LIBUTP_LIBS_QT="-lutp"

EXTRA_CONF_ARGS?=--enable-cli \
		 --disable-daemon \
		 --without-gtk \
		 --disable-mac \
		 --disable-nls

LITE_CONFIGURE_ENABLE=	lightweight

EXTRA_PATCHES=	${PATCHDIR}/disable-web
.endif

DOCS=		AUTHORS NEWS README
DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}${PKGNAMESUFFIX}

.include <bsd.port.pre.mk>

.if !empty(ICONV_LIB)
CONFIGURE_ARGS+=ac_cv_func_iconv_open=yes
.endif

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
	@${REINPLACE_CMD} -Ee '/^DHT_(CFLAGS|LIBS)=/d' \
		-e 's|third-party/[^ ]*Makefile||g' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} \
		-e 's,TRANSMISSION_TOP}/third-party/dht/libdht.a,DHT_LIBS},' \
		${WRKSRC}/qt/qtr.pro
	@${ECHO_CMD} 'DHT_LIBS = @DHT_LIBS@' >>${WRKSRC}/qt/config.pri.in

post-patch: general-patch

general-install:
	(cd ${WRKSRC} && ${COPYTREE_SHARE} \
		"${DOCS}" ${STAGEDIR}${DOCSDIR})

post-install: general-install

.include <bsd.port.post.mk>
