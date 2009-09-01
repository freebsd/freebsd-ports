# New ports collection makefile for:	transmission
# Date created:				08 October 2005
# Whom:					Mezz <mezz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	transmission
PORTVERSION=	1.74
PORTREVISION?=	0
CATEGORIES?=	net-p2p
MASTER_SITES=	http://download.m0k.org/${PORTNAME}/files/
PKGNAMESUFFIX?=	-cli

MAINTAINER?=	mezz@FreeBSD.org
COMMENT?=	A fast and lightweight CLI (command line) BitTorrent client

SLAVEPORT?=
.if ${SLAVEPORT}!="web"
LIB_DEPENDS?=	${GEN_LIB_DEPENDS}

# General dependencies
GEN_LIB_DEPENDS=curl.5:${PORTSDIR}/ftp/curl
GEN_RUN_DEPENDS=${LOCALBASE}/share/transmission/web/index.html:${PORTSDIR}/www/transmission-web

USE_GMAKE=	yes
USE_GNOME?=	pkgconfig
USE_OPENSSL=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=--with-ssl=${OPENSSLBASE} \
		--with-zlib=/usr \
		${EXTRA_CONF_ARGS}
EXTRA_CONF_ARGS?=--enable-cli \
		 --disable-daemon \
		 --disable-gtk \
		 --disable-libnotify \
		 --disable-mac \
		 --disable-nls

MAN1?=		transmissioncli.1
EXTRA_PATCHES=	${PATCHDIR}/disable-web
.endif

USE_BZIP2=	yes

DOCS=		AUTHORS COPYING NEWS README
DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}${PKGNAMESUFFIX}

general-patch:
	@${REINPLACE_CMD} -e 's|SUBDIRS = . sample.*|SUBDIRS = .|g' \
		${WRKSRC}/third-party/libevent/Makefile.*
	@${FIND} ${WRKSRC} -name Makefile.* | ${XARGS} ${REINPLACE_CMD} -e \
		's|noinst_PROGRAMS = |noinst_PROGRAMS = #|g'
.if ${SLAVEPORT}!="gtk2"
	@${REINPLACE_CMD} -e '/#define DISABLE_GETTEXT/s,/\* \(.*\) \*/,\1,' \
		${WRKSRC}/libtransmission/utils.h
.endif
	@${REINPLACE_CMD} -e \
		's|_pthread_flags=".*"|_pthread_flags="${PTHREAD_LIBS}"|g ; \
		s|libevent_source=system|libevent_source=bundled|g' \
			${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|-lrt||g' \
		${WRKSRC}/third-party/libevent/configure
	@${REINPLACE_CMD} -e 's|doc \\| \\|g' \
		${WRKSRC}/Makefile.in

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
