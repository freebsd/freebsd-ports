# New ports collection makefile for:    adcomplain
# http://www.rdrop.com/users/billmc/adcomplain.html
# Version required:     4.*
# Date created: 13 Sep 1997
# Whom:         ache@FreeBSD.org
#
# $Id: Makefile,v 1.19 1998/09/16 11:44:54 ache Exp $
#

DISTNAME=       adcomplain-4.42
CATEGORIES=     mail news
MASTER_SITES=   http://www.rdrop.com/users/billmc/
DISTFILES=      adcomplain.pl.uu

MAINTAINER=     ache@FreeBSD.org

USE_PERL5=      yes

EXTRACT_CMD=    /usr/bin/uudecode
EXTRACT_BEFORE_ARGS=    <
NO_WRKSUBDIR=	YES
NO_BUILD=       YES

post-patch:
	cd ${WRKSRC}; \
	cp adcomplain.pl adcomplain.pl.old; \
	sed 's=%PERL5%=${PERL}=' < adcomplain.pl.old > adcomplain.pl

do-install:
	cd ${WRKSRC}; \
	${INSTALL_SCRIPT} adcomplain.pl ${PREFIX}/bin/adcomplain

.include <bsd.port.mk>
