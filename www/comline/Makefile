# New ports collection makefile for:    comline
# Date created:         9 Dec 1995
# Whom:                 ache
#
# $FreeBSD$
#

PORTNAME=	comline
PORTVERSION=	4.0D
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.w3.org/pub/old/comline/ \
		ftp://ftp.w3.org/pub/libwww/old/ \
		ftp://ftp-eu.w3.org/pub/old/comline/ \
		ftp://ftp-eu.w3.org/pub/libwww/old/
DISTFILES=	w3c-libwww-4.0D.tar.gz \
		w3c_4.0D_src.tar.gz

MAINTAINER=	ache@freebsd.org

WRKSRC=		${WRKDIR}/WWW

do-build:
	cd ${WRKSRC}; ./BUILD comline

do-install:
	${INSTALL} -s -c -o ${BINOWN} -g ${BINGRP} -m ${BINMODE} \
		${WRKSRC}/ComLine/freebsd/w3c ${PREFIX}/bin

.include <bsd.port.mk>
