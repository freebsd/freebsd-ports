# New ports collection makefile for:    comline
# Version required:     4.0D
# Date created:         9 Dec 1995
# Whom:                 ache
#
# $Id: Makefile,v 1.8 1998/10/14 23:30:49 jseger Exp $
#

DISTNAME=	WWW
PKGNAME=        comline-4.0D
CATEGORIES=	www
MASTER_SITES=   ftp://ftp.w3.org/pub/old/comline/ \
		ftp://ftp.w3.org/pub/libwww/old/ \
		ftp://ftp-eu.w3.org/pub/old/comline/ \
		ftp://ftp-eu.w3.org/pub/libwww/old/
DISTFILES=      w3c-libwww-4.0D.tar.gz \
		w3c_4.0D_src.tar.gz

MAINTAINER=     ache@freebsd.org

BROKEN_ELF=	-lwww

do-build:
	cd ${WRKSRC}; ./BUILD comline

do-install:
	${INSTALL} -s -c -o ${BINOWN} -g ${BINGRP} -m ${BINMODE} \
		${WRKSRC}/ComLine/freebsd/w3c ${PREFIX}/bin

.include <bsd.port.mk>
