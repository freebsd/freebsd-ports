# New ports collection makefile for:    getbdf
# Version required:	?
# Date created:         30 August 1996
# Whom:                 ache
#
# $Id: Makefile,v 1.3 1996/08/31 05:11:40 asami Exp $
#

DISTNAME=       getbdf
PKGNAME=        getbdf-1.0
CATEGORIES=	x11
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
