# New ports collection makefile for:    getbdf
# Date created:         30 August 1996
# Whom:                 ache
#
# $Id: Makefile,v 1.1.1.1 1996/08/30 20:13:59 ache Exp $
#

DISTNAME=       getbdf
CATEGORIES+=	x11
MASTER_SITES=   ftp://ftp.ipa.fhg.de/pub/X/
EXTRACT_SUFX=   .tar.Z

MAINTAINER=     ache@FreeBSD.org

USE_X11=        yes
NO_WRKSUBDIR=   yes
ALL_TARGET=     getbdf

do-install:
	cd ${WRKSRC}; \
	${INSTALL} -c -s -o ${BINOWN} -g ${BINGRP} -m ${BINMODE} getbdf ${PREFIX}/bin

.include <bsd.port.mk>
