# New ports collection makefile for:	linemode
# Version required:     4.0D
# Date created:		17 April 1995
# Whom:			NIIMI Satoshi <sa2c@and.or.jp>
#
# $Id: Makefile,v 1.14 1998/10/14 23:53:17 jseger Exp $
#

DISTNAME=	WWW
PKGNAME=        linemode-4.0D
CATEGORIES=	www
MASTER_SITES=   ftp://ftp.w3.org/pub/linemode/old/ \
		ftp://ftp.w3.org/pub/libwww/old/ \
		ftp://ftp-eu.w3.org/pub/linemode/old/ \
		ftp://ftp-eu.w3.org/pub/libwww/old/
DISTFILES=      w3c-libwww-4.0D.tar.gz \
		www_4.0D_src.tar.gz

MAINTAINER=	sa2c@and.or.jp

BROKEN_ELF=	yes

do-build:
	cd ${WRKSRC}; ./BUILD linemode

do-install:
	${INSTALL} -c -s -o ${BINOWN} -g ${BINGRP} -m ${BINMODE} \
		${WRKSRC}/LineMode/freebsd/www ${PREFIX}/bin

.include <bsd.port.mk>
