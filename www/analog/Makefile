# New ports collection makefile for: analog
# Date created:		October 21st 1996
# Whom:			jfitz
#
# $FreeBSD$
#

PORTNAME=	analog
PORTVERSION= 	4.04
CATEGORIES=	www
MASTER_SITES=   http://www.analog.cx/ \
		http://brendanr.simplenet.com/analog/ \
		http://www.magma.ca/~brendanr/analog/ \
		http://www.monash.edu.au/mirror/analog/ \
		http://analog.gsp.com/ \
		http://analog.technomancer.com/ \
		ftp://ftp.netcasting.net/pub/packages/analog/ \
		ftp://download.netvision.net.il/pub/mirrors/analog/ \
		ftp://mabuse.phil.uni-passau.de/pub/mirrors/analog/

MAINTAINER=     ache@freebsd.org

Y2K=            http://www.analog.cx/

MAKE_FLAGS=     -DPREFIX=${PREFIX} -f
ALL_TARGET=     analog

do-install:
	install -d -o ${SHAREOWN} -g ${SHAREGRP} -m 555 \
		${PREFIX}/share/doc/analog
	install -d -o ${BINOWN} -g ${BINGRP} -m 755 \
		${PREFIX}/lib/analog/lang
	install -d -o nobody -g nogroup -m 755 \
		${PREFIX}/www/data/images
	cd ${WRKSRC}/images && \
		${INSTALL_DATA} * ${PREFIX}/www/data/images
	cd ${WRKSRC}/lang && \
		${INSTALL_DATA} * ${PREFIX}/lib/analog/lang
	cd ${WRKSRC} && \
		${INSTALL_PROGRAM} analog ${PREFIX}/bin
	cd ${WRKSRC} && \
	for file in analog.cfg ; do \
	    if [ ! -f ${PREFIX}/etc/$$file ] ; then \
		${INSTALL_DATA} -m 644 $$file ${PREFIX}/etc/$$file ; \
	    fi ; \
	${INSTALL_DATA} -m 644 $$file ${PREFIX}/etc/$$file-dist ; \
	done
.if !defined(NOPORTDOCS)
	cd ${WRKSRC}/docs && \
		${INSTALL_DATA} * ${PREFIX}/share/doc/analog
.endif

.include <bsd.port.mk>
