# Ports collection makefile for:  sarep
# http://tarp.worldserve.net/software/
# Version required:               1.*
# Date created:                   Feb 18, 1999
# Whom:                           ache
#
# $FreeBSD$
#

DISTNAME=       sarep-1.1
CATEGORIES=	textproc
MASTER_SITES=   http://tarp.worldserve.net/software/
EXTRACT_SUFX=

MAINTAINER=     ache@freebsd.org

RUN_DEPENDS=    ${PREFIX}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/Text/CSV_XS.pm:${PORTSDIR}/textproc/p5-Text-CSV_XS

EXTRACT_CMD=    $(SED)
EXTRACT_BEFORE_ARGS= 's=^\#!/usr/bin/perl =\#!${PERL} =' <
EXTRACT_AFTER_ARGS= | tr -d '\r' > ${WRKSRC}/sarep

NO_BUILD=       YES
NO_WRKSUBDIR=   yes

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/sarep ${PREFIX}/bin

.include <bsd.port.mk>
