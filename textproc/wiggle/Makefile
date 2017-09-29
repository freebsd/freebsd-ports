# Created by: mandree@FreeBSD.org
# $FreeBSD$

PORTNAME=	wiggle
PORTVERSION=	1.0
PORTREVISION=	3
CATEGORIES=	textproc
MASTER_SITES=	http://neil.brown.name/wiggle/

MAINTAINER=	mandree@FreeBSD.org
COMMENT=	Apply rejected patches and perform word-wise diffs

LICENSE=	GPLv2

BUILD_DEPENDS=	bash:shells/bash

BROKEN_powerpc64=	Does not build: error: nested functions are disabled, use -fnested-functions to re-enable

USES=		compiler:nestedfct gmake groff ncurses

MAKE_ARGS+=	CFLAGS="${CFLAGS} -I. -Wall -Wstrict-prototypes -Wextra -Wno-unused-parameter"

pre-patch:
		${REINPLACE_CMD} -Ee 's,\./dotest,bash ./dotest,' ${WRKSRC}/Makefile
		${REINPLACE_CMD} -Ee "s,/usr/bin/time -o .time -f '%U',," ${WRKSRC}/dotest
		${REINPLACE_CMD} -Ee 's|#include.*<endian.h>|#include <sys/endian.h>|' ${WRKSRC}/config.h
		@# fix a clang warning:
		${REINPLACE_CMD} -Ee 's|(^[[:space:]]+[[:<:]])cols = cols;|\1(void)cols;|' ${WRKSRC}/vpatch.c

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/wiggle ${STAGEDIR}${PREFIX}/bin/
		${INSTALL_MAN} ${WRKSRC}/wiggle.1 ${STAGEDIR}${PREFIX}/man/man1/

.include <bsd.port.mk>
