# New ports collection makefile for:    getbdf
# Date created:         30 August 1996
# Whom:                 ache
#
# $Id: Makefile,v 1.8 1996/08/06 04:59:00 asami Exp $
#

DISTNAME=       getbdf
CATEGORIES+=	x11
MASTER_SITES=   ftp://ftp.ipa.fhg.de/pub/X/
EXTRACT_SUFX=   .tar.Z

MAINTAINER=     ache@FreeBSD.org

NO_WRKSUBDIR=   yes
ALL_TARGET=     getbdf

do-install:
	cd ${WRKSRC}; \
	${INSTALL} -c -s -o ${BINOWN} -g ${BINGRP} -m ${BINMODE} getbdf ${PREFIX}/bin

.include <bsd.port.mk>
