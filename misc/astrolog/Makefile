# New ports collection makefile for:    astrolog
#
# http://rpkalf2.mach.uni-karlsruhe.de/~ferber/astrolog/
# http://www.magitech.com/~cruiser1/astrolog.htm
#
# Version required:     5.30
# Date created:         31 July 1995
# Whom:                 faulkner@cactus.org
#
# $Id: Makefile,v 1.13 1998/11/28 05:39:00 asami Exp $
#

DISTNAME=       ast53unx
PKGNAME=        astrolog-5.30
CATEGORIES=     misc
MASTER_SITES=   http://www.astrolog.org/ftp/ephem/ \
		http://www.astrolog.org/ftp/ \
		ftp://ftp.kiarchive.ru/pub/unix/magick/astrology/astrolog/
EXTRACT_ONLY=   ${DISTNAME}.shr
EPHEM=          LRZ5_24 CHI_24 CPJV_24
DISTFILES=      ${EXTRACT_ONLY} ${EPHEM}

MAINTAINER=     ache@FreeBSD.ORG

USE_XLIB=	yes
EXTRACT_CMD=    ${SH}
EXTRACT_BEFORE_ARGS=	# empty
EXTRACT_AFTER_ARGS=	# empty
DIST_SUBDIR=    astrolog
ALL_TARGET=     astrolog
NO_WRKSUBDIR=   Yes

do-install:
	-@${MKDIR} ${PREFIX}/lib/astrolog
	cd ${DISTDIR}/${DIST_SUBDIR} && \
		${INSTALL_DATA} ${EPHEM} ${PREFIX}/lib/astrolog
	cd ${WRKSRC} && \
		if [ -f ${PREFIX}/lib/astrolog/astrolog.dat ] ; then \
			${INSTALL_DATA} astrolog.dat ${PREFIX}/lib/astrolog/astrolog.dat-dist; \
		else \
			${INSTALL_DATA} astrolog.dat ${PREFIX}/lib/astrolog; \
		fi
	cd ${WRKSRC} && ${INSTALL_PROGRAM} astrolog ${PREFIX}/bin
	-@${MKDIR} ${PREFIX}/share/doc/astrolog
	cd ${WRKSRC} && \
		${INSTALL_DATA} Helpfile.530 ${PREFIX}/share/doc/astrolog
	cd ${WRKSRC} && \
		${INSTALL_DATA} Update.530 ${PREFIX}/share/doc/astrolog
	cd ${WRKSRC} && \
		${INSTALL_DATA} README.530 ${PREFIX}/share/doc/astrolog
	@echo
	@echo "See the file ${PREFIX}/share/doc/astrolog/Helpfile.530 for help"
	@echo "and tune ${PREFIX}/lib/astrolog/astrolog.dat"

.include <bsd.port.mk>
