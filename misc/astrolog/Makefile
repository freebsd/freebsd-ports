# New ports collection makefile for:    astrolog
#
# http://www-rpk.mach.uni-karlsruhe.de/~ferber/astrolog/
# http://www.magitech.com/~cruiser1/astrolog.htm
#
# Version required:     5.20
# Date created:         31 July 1995
# Whom:                 faulkner@cactus.org
#
# $Id: Makefile,v 1.5 1996/11/11 05:49:12 obrien Exp $
#

DISTNAME=       astrolog-5.20
CATEGORIES=     misc x11
MASTER_SITES=   http://www-rpk.mach.uni-karlsruhe.de/~ferber/astrolog/ \
		ftp://ftp.relcom.ru/unix/magick/astrology/astrolog/
DISTFILES=      ${EXTRACT_ONLY} ${EPHEM:S/$/.gz/}
EXTRACT_ONLY=   ${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=     ache@FreeBSD.ORG

DIST_SUBDIR=    astrolog
WRKSRC=         ${WRKDIR}/${DISTNAME}/src

EPHEM=          lrz5_24 chi_24 cpjv_24

post-extract:
	cd ${WRKSRC}/..; \
		for i in ${EPHEM}; do \
			zcat ${DISTDIR}/${DIST_SUBDIR}/$$i.gz > \
				`echo $$i | tr '[:lower:]' '[:upper:]'`; \
		done

post-patch:
	cd ${WRKSRC}/../docs; \
		sed 's/^@tpindex/@tindex/' < astrolog.texinfo > a.texinfo; \
		mv a.texinfo astrolog.texinfo

post-build:
	cd ${WRKSRC}/../docs; \
		makeinfo --no-split astrolog.texinfo -o astrolog.info; \
		gzip -f astrolog.info

do-install:
	-@mkdir ${PREFIX}/lib/astrolog
	cd ${WRKSRC}/..; \
		${INSTALL} -c -m ${SHAREMODE} -o ${SHAREOWN} -g ${SHAREGRP} \
			LRZ5_* CHI_* CPJV_* ${PREFIX}/lib/astrolog
	cd ${WRKSRC}/..; \
		if [ -f ${PREFIX}/lib/astrolog/astrolog.dat ] ; then \
			${INSTALL} -c -m ${SHAREMODE} -o ${SHAREOWN} -g ${SHAREGRP} \
				astrolog.dat ${PREFIX}/lib/astrolog/astrolog.dat-dist; \
		else \
			${INSTALL} -c -m 644 -o ${SHAREOWN} -g ${SHAREGRP} \
				astrolog.dat ${PREFIX}/lib/astrolog; \
		fi
	cd ${WRKSRC}; \
		${INSTALL} -c -s -m ${BINMODE} -o ${BINOWN} -g ${BINGRP} \
			astrolog ${PREFIX}/bin
	cd ${WRKSRC}/../docs; \
		$(INSTALL) -c -m ${INFOMODE} -o $(INFOOWN) -g $(INFOGRP) \
			astrolog.info.gz ${PREFIX}/info
	-@mkdir ${PREFIX}/share/astrolog
	cd ${WRKSRC}/..; \
		${INSTALL} -c -m ${SHAREMODE} -o ${SHAREOWN} -g ${SHAREGRP} \
			helpfile.520 readme.520 ${PREFIX}/share/astrolog
	@echo
	@echo "See the file ${PREFIX}/share/astrolog/helpfile.520 for help"
	@echo "and tune ${PREFIX}/lib/astrolog/astrolog.dat,"
	@echo "also look at ${PREFIX}/info/astrolog.info.gz"

.include <bsd.port.mk>
