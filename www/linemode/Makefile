# New ports collection makefile for:	cern_linemode
# Version required:	3.0 / 3.0
# Date created:		17 April 1995
# Whom:			NIIMI Satoshi <sa2c@and.or.jp>
#
# $Id: Makefile,v 1.4 1995/04/25 10:48:29 asami Exp $
#

DISTNAME=	WWW
PKGNAME=	cern_linemode-3.0
CATEGORIES+=	networking
MASTER_SITES=	ftp://ftp.w3.org/pub/www/src/
DISTFILES=	WWWLineMode_3.0.tar.Z WWWLibrary_3.0.tar.Z

MAINTAINER=	sa2c@and.or.jp

PATCH_STRIP=	-p1

do-install:
	install -c -s -o ${BINOWN} -g ${BINGRP} -m ${BINMODE} \
		${WRKSRC}/LineMode/unix/www ${PREFIX}/bin

.include <bsd.port.mk>
