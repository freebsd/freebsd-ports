# New ports collection makefile for:    webcopy
# Version required:     0.98b7
# Date created:         14 Sep 1996
# Whom:                 ache
#
# $Id: Makefile,v 1.3 1996/09/15 16:41:28 ache Exp $
#

# WWW site: http://www.inf.utfsm.cl/~vparada/webcopy.html

DISTNAME=       webcopy-0.98b7
CATEGORIES+=    www
MASTER_SITES=   ftp://ftp.inf.utfsm.cl/pub/utfsm/perl/
DISTFILES=      webcopy.tgz

MAINTAINER=     ache@FreeBSD.ORG

ALL_TARGET=
NO_PACKAGE= yes # This program cannot be distributed if modified in any way
NO_CDROM= yes   # Don't sell for profit without written permission

do-install:
	cd ${WRKSRC}; ${INSTALL_SCRIPT} webcopy ${PREFIX}/bin

.include <bsd.port.mk>
