# New ports collection makefile for:	cern_linemode
# Version required:	3.0 / 3.0
# Date created:		17 April 1995
# Whom:			NIIMI Satoshi <sa2c@and.or.jp>
#
# $Id$
#

DISTNAME=	WWW
PKGNAME=	cern_linemode-3.0
CATEGORIES+=	networking
MASTER_SITES=	ftp://ftp.w3.org/pub/www/src/
# ^is this correct?
DISTFILES=	WWWLineMode_3.0.tar.Z WWWLibrary_3.0.tar.Z

PATCH_STRIP=	-p1

install: build
	install -c -s -o ${BINOWN} -g ${BINGRP} -m ${BINMODE} \
		${WRKSRC}/LineMode/unix/www ${PREFIX}/bin

.include <bsd.port.mk>
