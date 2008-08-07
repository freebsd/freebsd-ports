# New ports collection makefile for:	transmission
# Date created:				08 October 2005
# Whom:					Mezz <mezz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	transmission
PORTVERSION=	1.31
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
GEN_LIB_DEPENDS=curl.4:${PORTSDIR}/ftp/curl
GEN_RUN_DEPENDS=${LOCALBASE}/share/transmission/web/index.html:${PORTSDIR}/www/transmission-web

USE_GNOME?=	gnometarget pkgconfig
USE_OPENSSL=	yes

MAN1?=		transmissioncli.1
.endif

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_AUTOTOOLS=	autoconf:262:env aclocal:19:env automake:19:env libtool:15:env
GNU_CONFIGURE=	yes

DOCS=		AUTHORS COPYING NEWS README

DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}${PKGNAMESUFFIX}
EXTRA_PATCHES=	${PATCHDIR}/${PORTNAME}${PKGNAMESUFFIX}-configure.ac

general-patch:
	@${REINPLACE_CMD} -e 's|SUBDIRS = . sample.*|SUBDIRS = .|g' \
		${WRKSRC}/third-party/libevent/Makefile.*
	@${FIND} ${WRKSRC} -name Makefile.* | ${XARGS} ${REINPLACE_CMD} -e \
		's|$$(OPENSSL_CFLAGS)||g ; s|$$(OPENSSL_LIBS)||g ; \
		s|noinst_PROGRAMS = |noinst_PROGRAMS = #|g'

post-patch: general-patch

pre-configure:
	@(cd ${WRKSRC} && ${SETENV} ${AUTOTOOLS_ENV} ${AUTORECONF} -W none)
	@${REINPLACE_CMD} -e \
		's|CFLAGS="-g -Wall.*"|CFLAGS="${CFLAGS} -Wall -W"|g ; \
		s|CXXFLAGS="-g -Wall.*"|CXXFLAGS="${CXXFLAGS} -Wall -W"|g ; \
		s|_pthread_flags=".*"|_pthread_flags="${PTHREAD_LIBS}"|g' \
			${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|-lrt||g' \
		${WRKSRC}/third-party/libevent/configure

general-install:
.ifndef (NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

post-install: general-install

.include <bsd.port.mk>
