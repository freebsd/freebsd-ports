# New ports collection makefile for:    adcomplain
# http://www.rdrop.com/users/billmc/adcomplain.html
# Version required:     3.*
# Date created: 13 Sep 1997
# Whom:         ache@FreeBSD.org
#
# $Id: Makefile,v 1.20 1998/10/07 10:13:49 ache Exp $
#

DISTNAME=       adcomplain-3.47
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
