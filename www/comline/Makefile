# New ports collection makefile for:    comline
# Version required:     4.0D
# Date created:         9 Dec 1995
# Whom:                 ache
#
# $Id: Makefile,v 1.4 1996/01/11 01:20:17 ache Exp $
#

DISTNAME=	WWW
PKGNAME=        comline-4.0D
CATEGORIES+=	www
MASTER_SITES=   ftp://ftp.w3.org/pub/comline/ \
		ftp://ftp.w3.org/pub/libwww/
DISTFILES=      libwww_4.0D_src.tar.gz \
		w3c_4.0D_src.tar.gz

MAINTAINER=     ache@freebsd.org

do-build:
	cd ${WRKSRC}; ./BUILD comline

do-install:
	${INSTALL} -s -c -o ${BINOWN} -g ${BINGRP} -m ${BINMODE} \
		${WRKSRC}/ComLine/freebsd/w3c ${PREFIX}/bin

.include <bsd.port.mk>
