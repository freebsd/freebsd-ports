# New ports collection makefile for:    adcomplain
# http://www.rdrop.com/users/billmc/adcomplain.html
# Version required:     3.*
# Date created: 13 Sep 1997
# Whom:         ache@FreeBSD.org
#
# $Id: Makefile,v 1.15 1998/06/27 05:19:12 asami Exp $
#

DISTNAME=       adcomplain-3.33
CATEGORIES=     mail news
MASTER_SITES=   http://www.rdrop.com/users/billmc/
DISTFILES=      adcomplain.pl.uu

MAINTAINER=     ache@FreeBSD.org

EXTRACT_CMD=    /usr/bin/uudecode
EXTRACT_BEFORE_ARGS=    <
NO_WRKSUBDIR=	YES
NO_BUILD=       YES

do-install:
	cd ${WRKSRC}; \
	${INSTALL_SCRIPT} adcomplain.pl ${PREFIX}/bin/adcomplain

.include <bsd.port.mk>
