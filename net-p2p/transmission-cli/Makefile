# $FreeBSD$

PORTNAME=	transmission
PORTVERSION=	2.82
PORTREVISION?=	0
CATEGORIES?=	net-p2p
#MASTER_SITES=	http://download.m0k.org/${PORTNAME}/files/
MASTER_SITES=	http://transmission.cachefly.net/
PKGNAMESUFFIX?=	-cli

MAINTAINER?=	crees@FreeBSD.org
COMMENT?=	Lightweight CLI (command line) BitTorrent client and utilities

SLAVEPORT?=	cli

# Odd arrangement here-- cli is MIT, everything else is GPL
.if ${SLAVEPORT} == cli
LICENSE=	MIT
.else
LICENSE=	GPLv2
.endif
LICENSE_FILE=	${WRKSRC}/COPYING

CONFLICTS_INSTALL=	${PORTNAME}${PKGNAMESUFFIX}-2.5*

OPTIONS_DEFINE=	LITE

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${SLAVEPORT} != web
LIB_DEPENDS?=	${GEN_LIB_DEPENDS}

# General dependencies
GEN_LIB_DEPENDS=libcurl.so:${PORTSDIR}/ftp/curl \
		libevent-2.0.so.6:${PORTSDIR}/devel/libevent2
GEN_RUN_DEPENDS=${LOCALBASE}/share/transmission/web/index.html:${PORTSDIR}/www/transmission-web

# This is master port of transmission-*, so don't override USES definition 
USES+=		gmake pkgconfig iconv
USE_OPENSSL=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib ${ICONV_LIB}
CONFIGURE_ARGS=--with-zlib=/usr \
		${EXTRA_CONF_ARGS}
EXTRA_CONF_ARGS?=--enable-cli \
		 --disable-daemon \
		 --without-gtk \
		 --disable-mac \
		 --disable-nls

.if ${PORT_OPTIONS:MLITE}
CONFIGURE_ARGS+=--enable-lightweight
.endif

MAN1?=		transmission-cli.1 transmission-create.1 transmission-edit.1 \
		transmission-show.1
EXTRA_PATCHES=	${PATCHDIR}/disable-web
.endif

USE_XZ=		yes

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
		's|_pthread_flags=".*"|_pthread_flags="${PTHREAD_LIBS}"|g ; \
		s|rt_clock_gettime=yes|rt_clock_gettime=no|g ; \
		s|" == "|" = "|g ; s|$$with_ssl.*/usr;|${OPENSSLBASE};|g' \
			${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|doc \\| \\|g' \
		${WRKSRC}/Makefile.in
.if ${SLAVEPORT} != cli
	@${REINPLACE_CMD} -e 's|utils \\|\\|g' \
		${WRKSRC}/Makefile.in
.endif

post-patch: general-patch

general-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
.for i in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

post-install: general-install

.include <bsd.port.mk>
