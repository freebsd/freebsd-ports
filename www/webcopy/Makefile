# New ports collection makefile for:    webcopy
# Version required:     0.98b7
# Date created:         14 Sep 1996
# Whom:                 ache
#
# $Id: Makefile,v 1.6 1996/09/11 04:44:19 asami Exp $
#

# WWW site: http://www.inf.utfsm.cl/~vparada/webcopy.html

DISTNAME=       webcopy-0.98b7
CATEGORIES+=    www
MASTER_SITES=   ftp://ftp.inf.utfsm.cl/pub/utfsm/perl/
DISTFILES=      webcopy.tgz
ALL_TARGET=

MAINTAINER=     ache@FreeBSD.ORG

NO_PACKAGE=     yes     # See License at the start of the script

do-install:
	cd ${WRKSRC}; ${INSTALL_SCRIPT} webcopy ${PREFIX}/bin

.include <bsd.port.mk>
