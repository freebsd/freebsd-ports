# Ports collection makefile for:  sarep
# http://tarp.linuxos.org/software/
# Version required:               0.*
# Date created:                   Feb 18, 1999
# Whom:                           ache
#
# $FreeBSD$
#

DISTNAME=       sarep-0.5
CATEGORIES=	textproc
MASTER_SITES=   http://tarp.linuxos.org/software/
EXTRACT_SUFX=

MAINTAINER=     ache@freebsd.org

EXTRACT_CMD=    $(SED)
EXTRACT_BEFORE_ARGS= 's=^\#!/usr/bin/perl =\#!${PERL} =' <
EXTRACT_AFTER_ARGS= | tr -d '\r' > ${WRKSRC}/sarep

NO_BUILD=       YES
NO_WRKSUBDIR=   yes

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/sarep ${PREFIX}/bin

.include <bsd.port.mk>
