# New ports collection makefile for:    adcomplain
# http://www.rdrop.com/users/billmc/adcomplain.html
# Version required:     2.84
# Date created: 13 Sep 1997
# Whom:         ache@FreeBSD.org
#
# $Id: Makefile,v 1.7 1997/11/15 10:35:49 asami Exp $
#

DISTNAME=       adcomplain-2.84
CATEGORIES=     mail news
MASTER_SITES=   http://www.rdrop.com/users/billmc/
DISTFILES=      adcomplain.pl.uu

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
