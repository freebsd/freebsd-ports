# New ports collection makefile for:    adcomplain
# http://www.rdrop.com/users/billmc/
# Version required:     1.6
# Date created: 13 Sep 1997
# Whom:         ache@FreeBSD.org
#
# $Id: Makefile,v 1.2 1997/03/28 10:10:05 asami Exp $
#

DISTNAME=       adcomplain-1.6
DISTFILES=      adcomplain.pl.uu
CATEGORIES=     mail news
MASTER_SITES=   http://www.rdrop.com/users/billmc/

MAINTAINER=     ache@FreeBSD.org

EXTRACT_CMD=    /usr/bin/uudecode
EXTRACT_BEFORE_ARGS=    <
NO_WRKSUBDIR=	YES
NO_CONFIGURE=   YES
NO_BUILD=       YES

do-install:
	cd ${WRKSRC}; \
	${INSTALL_SCRIPT} adcomplain.pl ${PREFIX}/bin/adcomplain

.include <bsd.port.mk>
