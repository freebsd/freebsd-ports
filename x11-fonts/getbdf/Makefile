# New ports collection makefile for:    getbdf
# Date created:         30 August 1996
# Whom:                 ache
#
# $FreeBSD$
#

PORTNAME=	getbdf
PORTVERSION=	1.0
CATEGORIES=	x11-fonts
MASTER_SITES=   ftp://ftp.nstu.ru/pub/sources/x/fonts/utils/
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	ache@FreeBSD.org
COMMENT=	Convert any X server font to .bdf format

PLIST_FILES=	bin/getbdf
USE_PERL5_BUILD=yes
USE_X_PREFIX=	yes
NO_WRKSUBDIR=	yes
ALL_TARGET=	getbdf

pre-patch:
	@${PERL} -pi -e 's,<malloc.h>,<stdlib.h>,' \
		${WRKSRC}/Xargs.c ${WRKSRC}/getbdf.c

do-install:
	cd ${WRKSRC}; \
	${INSTALL} -c -s -o ${BINOWN} -g ${BINGRP} -m ${BINMODE} getbdf ${PREFIX}/bin

.include <bsd.port.mk>
