# New ports collection makefile for:	transmission
# Date created:				08 October 2005
# Whom:					Mezz <mezz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	transmission
PORTVERSION=	2.22
PORTREVISION?=	0
CATEGORIES?=	net-p2p
MASTER_SITES=	http://download.m0k.org/${PORTNAME}/files/
PKGNAMESUFFIX?=	-cli

MAINTAINER?=	mezz@FreeBSD.org
COMMENT?=	A lightweight CLI (command line) BitTorrent client and utilities

SLAVEPORT?=	cli
.if ${SLAVEPORT}!="web"
LIB_DEPENDS?=	${GEN_LIB_DEPENDS}

# General dependencies
GEN_LIB_DEPENDS=curl.6:${PORTSDIR}/ftp/curl \
		event-2.0.5:${PORTSDIR}/devel/libevent2
GEN_RUN_DEPENDS=${LOCALBASE}/share/transmission/web/index.html:${PORTSDIR}/www/transmission-web

USE_GMAKE=	yes
USE_GNOME?=	pkgconfig
USE_OPENSSL=	yes
GNU_CONFIGURE=	yes
CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}"
CONFIGURE_ARGS=--with-zlib=/usr \
		--disable-libappindicator \
		--disable-gconf2 \
		${EXTRA_CONF_ARGS}
EXTRA_CONF_ARGS?=--enable-cli \
		 --disable-daemon \
		 --disable-gtk \
		 --disable-libnotify \
		 --disable-mac \
		 --disable-nls

MAN1?=		transmission-cli.1 transmission-create.1 transmission-edit.1 \
		transmission-show.1
EXTRA_PATCHES=	${PATCHDIR}/disable-web
.endif

USE_XZ=	yes

DOCS=		AUTHORS COPYING NEWS README
DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}${PKGNAMESUFFIX}

general-patch:
	@${FIND} ${WRKSRC} -name Makefile.in | ${XARGS} ${REINPLACE_CMD} -e \
		's|noinst_PROGRAMS = |noinst_PROGRAMS = #|g'
.if ${SLAVEPORT}!="gtk2"
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
.if ${SLAVEPORT}!="cli"
	@${REINPLACE_CMD} -e 's|utils \\|\\|g' \
		${WRKSRC}/Makefile.in
.endif

post-patch: general-patch

general-install:
.ifndef (NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

post-install: general-install

.include <bsd.port.mk>
