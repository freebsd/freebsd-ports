# New ports collection makefile for:   freepops
# Date created:                19 Feb 2005
# Whom:                        Filippo Natali <filippo@widestore.net>
#
# $FreeBSD$
#

PORTNAME=	freepops
PORTVERSION=	0.2.7
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	freepops

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Extensible webmail to pop3 interface

LIB_DEPENDS=	expat.6:${PORTSDIR}/textproc/expat2 \
		curl:${PORTSDIR}/ftp/curl

MAN1=		freepopsd.1 freepops-updater-dialog.1 freepops-updater-zenity.1

USE_BISON=	build
USE_GMAKE=	yes
HAS_CONFIGURE=	yes
CONFIGURE_SCRIPT=	configure.sh
CONFIGURE_ARGS=	fbsd
CFLAGS+=	-I${OPENSSLBASE}/include ${PTHREAD_CFLAGS}

post-patch:
	@${REINPLACE_CMD} -e \
		's|^#!/bin/bash|#!/bin/sh|; \
		 s|\(WHERE=\)/usr/local|\1${PREFIX}|; \
		 s|/usr/local|${LOCALBASE}|; \
		 s|^CC=$${CC:-gcc}||; \
		 s|^CXX=$${CXX:-g++}||; \
		 s|=$${CFLAGS:-"-O2 -g3 \(.*\)"}|="$${CFLAGS} \1"|' \
		${WRKSRC}/${CONFIGURE_SCRIPT}
	@${REINPLACE_CMD} -e \
		's|$$(PREFIX)|${PREFIX}/|; \
		 s|share/\(man/man1\)|\1|; \
		 s|$$(DESTDIR)\(etc/freepops\)|${PREFIX}/\1|; \
		 s|\(cp config\.lua\) .*|\1 ${PREFIX}/etc/freepops/config.lua.sample|; \
		 s|for D in modules/include/\*/;|for D in modules/include/*;|' \
		${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e \
		's|-pthread|${PTHREAD_LIBS}|g'\
		${WRKSRC}/src/Makefile
	@${REINPLACE_CMD} -e \
		's|^#CURL_LD_FLAGS|CURL_LD_FLAGS|' \
		${WRKSRC}/src/Makefile

post-install:
	@${CHMOD} ${SHAREMODE} ${DATADIR}/lua/*.lua
	@[ -f ${PREFIX}/etc/freepops/config.lua ] || \
		${CP} -f ${PREFIX}/etc/freepops/config.lua.sample \
		${PREFIX}/etc/freepops/config.lua

.include <bsd.port.mk>
