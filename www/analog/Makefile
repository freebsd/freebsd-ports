# New ports collection makefile for: analog
# http://www.statslab.cam.ac.uk/~sret1/analog/
# Version required:     3.*
# Date created:		October 21st 1996
# Whom:			jfitz
#
# $Id: Makefile,v 1.13 1999/01/13 04:00:06 scrappy Exp $
#

DISTNAME=       analog3.11
PKGNAME=        analog-3.11
CATEGORIES=	www
MASTER_SITES=   http://www.statslab.cam.ac.uk/~sret1/analog/ \
		http://www.lightside.net/analog/ \
		http://www.gamesdomain.com/analog/ \
		http://www.monash.edu.au/mirror/analog/ \
		http://www.gamesdomain.co.uk/analog/ \
		ftp://download.netvision.net.il/pub/mirrors/analog/ \
		ftp://mabuse.phil.uni-passau.de/pub/mirrors/analog/

MAINTAINER=     ache@freebsd.org

Y2K=		http://www.statslab.cam.ac.uk/~sret1/analog/

MAKE_FLAGS=     -DPREFIX=${PREFIX} -f

do-install:
	install -d -o ${SHAREOWN} -g ${SHAREGRP} -m 555 \
		${PREFIX}/share/doc/analog
	install -d -o ${BINOWN} -g ${BINGRP} -m 755 \
		${PREFIX}/lib/analog/lang
	install -d -o nobody -g nogroup -m 755 \
		${PREFIX}/www/data/images
	cd ${WRKSRC}/docs && \
		${INSTALL_DATA} * ${PREFIX}/share/doc/analog
	cd ${WRKSRC}/images && \
		${INSTALL_DATA} * ${PREFIX}/www/data/images
	cd ${WRKSRC}/lang && \
		${INSTALL_DATA} * ${PREFIX}/lib/analog/lang
	cd ${WRKSRC} && \
		${INSTALL_PROGRAM} analog ${PREFIX}/bin
	cd ${WRKSRC} && \
	for file in domains.tab ; do \
	    if [ -f ${PREFIX}/lib/analog/$$file ] ; then \
		${INSTALL_DATA} -m 644 $$file ${PREFIX}/lib/analog/$$file-dist ; \
	    else \
		${INSTALL_DATA} -m 644 $$file ${PREFIX}/lib/analog/$$file ; \
	    fi ; \
	done
	cd ${WRKSRC} && \
	for file in analog.cfg ; do \
	    if [ -f ${PREFIX}/etc/$$file ] ; then \
		${INSTALL_DATA} -m 644 $$file ${PREFIX}/etc/$$file-dist ; \
	    else \
		${INSTALL_DATA} -m 644 $$file ${PREFIX}/etc/$$file ; \
	    fi ; \
	done

.include <bsd.port.mk>
