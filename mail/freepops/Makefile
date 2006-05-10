# New ports collection makefile for:   freepops
# Date created:                19 Feb 2005
# Whom:                        Filippo Natali <filippo@widestore.net>
#
# $FreeBSD$
#

PORTNAME=	freepops
PORTVERSION=	0.0.96
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	freepops

MAINTAINER=	filippo.natali@gmail.com
COMMENT=	Extensible webmail to pop3 interface

LIB_DEPENDS=	expat.6:${PORTSDIR}/textproc/expat2 \
		curl:${PORTSDIR}/ftp/curl
BUILD_DEPENDS=	bison:${PORTSDIR}/devel/bison

MAN1=		freepopsd.1
USE_GMAKE=	yes
HAS_CONFIGURE=	yes
CONFIGURE_SCRIPT=	configure.sh
CONFIGURE_ARGS=	fbsd
CFLAGS+=	-I${OPENSSLBASE}/include ${PTHREAD_CFLAGS}

post-patch:
	@${REINPLACE_CMD} -e \
		's|\(WHERE=\)/usr/local|\1${PREFIX}|; \
		 s|^#!/bin/bash|#!/bin/sh|; \
		 s|/usr/local|${LOCALBASE}|; \
		 s|^CC=gcc||; \
		 s|-O2 -g3 -march=i486|${CFLAGS}|' \
		${WRKSRC}/${CONFIGURE_SCRIPT}
	@${REINPLACE_CMD} -e \
		's|$$(PREFIX)|${PREFIX}/|; \
		 s|share/\(man/man1\)|\1|; \
		 s|$$(DESTDIR)\(/etc/freepops\)|${PREFIX}\1|; \
		 s|\(cp config\.lua\) .*|\1 ${PREFIX}/etc/freepops/config.lua.sample|' \
		${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e \
		's|-pthread|${PTHREAD_LIBS}|g'\
		${WRKSRC}/src/Makefile
	@${REINPLACE_CMD} -e \
		's|^#!/bin/bash|#!/bin/sh|' \
		${WRKSRC}/modules/src/curl_lua/find_curl.sh
	@${REINPLACE_CMD} -e \
		's|^#CURL_LD_FLAGS|CURL_LD_FLAGS|' \
		${WRKSRC}/src/Makefile

post-install:
	@${CHMOD} ${SHAREMODE} ${DATADIR}/lua/*.lua
	@[ -f ${PREFIX}/etc/freepops/config.lua ] || \
		${CP} -f ${PREFIX}/etc/freepops/config.lua.sample \
		${PREFIX}/etc/freepops/config.lua

.include <bsd.port.mk>
