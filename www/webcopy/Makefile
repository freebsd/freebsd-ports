# New ports collection makefile for:    webcopy
# Version required:     0.98b7
# Date created:         14 Sep 1996
# Whom:                 ache
#
# $Id: Makefile,v 1.1.1.1 1996/09/14 00:59:32 ache Exp $
#

# WWW site: http://www.inf.utfsm.cl/~vparada/webcopy.html

DISTNAME=       webcopy-0.98b7
CATEGORIES+=    www
MASTER_SITES=   ftp://ftp.inf.utfsm.cl/pub/utfsm/perl/
DISTFILES=      webcopy.tgz

MAINTAINER=     ache@FreeBSD.ORG

ALL_TARGET=
NO_CDROM=	yes     # Don't sell for profit without written permission

do-install:
	cd ${WRKSRC}; ${INSTALL_SCRIPT} webcopy ${PREFIX}/bin

.include <bsd.port.mk>
