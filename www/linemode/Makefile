# New ports collection makefile for:	cern_linemode
# Version required:     4.0B
# Date created:		17 April 1995
# Whom:			NIIMI Satoshi <sa2c@and.or.jp>
#
# $Id: Makefile,v 1.8 1995/12/10 18:49:41 ache Exp $
#

DISTNAME=	WWW
PKGNAME=        cern_linemode-4.0B
CATEGORIES+=	www
MASTER_SITES=   ftp://ftp.w3.org/pub/linemode/ \
		ftp://ftp.w3.org/pub/libwww/
DISTFILES=      libwww_4.0B_src.tar.gz \
		www_4.0B_src.tar.gz

MAINTAINER=	sa2c@and.or.jp

do-build:
	cd ${WRKSRC}; ./BUILD linemode

do-install:
	${INSTALL} -c -s -o ${BINOWN} -g ${BINGRP} -m ${BINMODE} \
		${WRKSRC}/LineMode/freebsd/www ${PREFIX}/bin

.include <bsd.port.mk>
