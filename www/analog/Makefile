# New ports collection makefile for: analog
# Version required:     2.11
# Date created:		October 21st 1996
# Whom:			jfitz
#
# $Id: Makefile,v 1.8 1997/05/02 23:16:50 ache Exp $
#

DISTNAME=       analog2.11
PKGNAME=        analog-2.11
CATEGORIES=	www
MASTER_SITES=   http://www.statslab.cam.ac.uk/~sret1/analog/ \
		http://www.lightside.net/analog/ \
		http://www.gamesdomain.com/analog/ \
		http://www.monash.edu.au/mirror/analog/ \
		http://www.gamesdomain.co.uk/analog/ \
		ftp://download.netvision.net.il/pub/mirrors/analog/ \
		ftp://mabuse.phil.uni-passau.de/pub/mirrors/analog/

MAINTAINER=	jfitz@freebsd.org

do-install:
	install -d -o ${SHAREOWN} -g ${SHAREGRP} -m 555 \
		${PREFIX}/share/doc/analog
	install -d -o ${BINOWN} -g ${BINGRP} -m 755 \
		${PREFIX}/lib/analog/lang
	install -d -o nobody -g nogroup -m 755 \
		${PREFIX}/www/data/images
	cd ${WRKSRC} && \
		${INSTALL_DATA} Readme.html Licence \
		${PREFIX}/share/doc/analog
	cd ${WRKSRC}/images && \
		${INSTALL_DATA} * ${PREFIX}/www/data/images
	cd ${WRKSRC}/lang && \
		${INSTALL_DATA} * ${PREFIX}/lib/analog/lang
	cd ${WRKSRC} && \
		${INSTALL_PROGRAM} analog ${PREFIX}/bin
	cd ${WRKSRC} && \
	for file in domains.tab primes.tab analog.cfg ; do \
	    if [ -f ${PREFIX}/lib/analog/$$file ] ; then \
		${INSTALL_DATA} -m 644 $$file ${PREFIX}/lib/analog/$$file-dist ; \
	    else \
		${INSTALL_DATA} -m 644 $$file ${PREFIX}/lib/analog/$$file ; \
	    fi ; \
	done
	cd ${WRKSRC} && make form
	cd ${WRKSRC} && \
		${INSTALL_PROGRAM} analform.cgi ${PREFIX}/www/cgi-bin
	cd ${WRKSRC} && \
		${INSTALL_DATA} analogform.html \
		${PREFIX}/share/doc/analog

.include <bsd.port.mk>
