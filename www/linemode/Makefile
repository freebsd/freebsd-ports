# New ports collection makefile for:	cern_linemode
# Version required:     4.0p7
# Date created:		17 April 1995
# Whom:			NIIMI Satoshi <sa2c@and.or.jp>
#
# $Id: Makefile,v 1.6 1995/11/27 04:10:16 asami Exp $
#

DISTNAME=	WWW
PKGNAME=        cern_linemode-4.0p7
CATEGORIES+=	www
MASTER_SITES=   ftp://ftp.w3.org/pub/linemode/ \
		ftp://ftp.w3.org/pub/libwww/
DISTFILES=      www_4.0pre7_src.tar.gz \
		libwww_4.0pre7_src.tar.gz

MAINTAINER=	sa2c@and.or.jp

do-build:
	cd ${WRKSRC}; ./BUILD linemode

do-install:
	${INSTALL} -c -s -o ${BINOWN} -g ${BINGRP} -m ${BINMODE} \
		${WRKSRC}/LineMode/freebsd/www ${PREFIX}/bin

.include <bsd.port.mk>
