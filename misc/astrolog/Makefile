# New ports collection makefile for:    astrolog
#
# http://rpkalf2.mach.uni-karlsruhe.de/~ferber/astrolog/
# http://www.magitech.com/~cruiser1/astrolog.htm
#
# Version required:     5.30
# Date created:         31 July 1995
# Whom:                 faulkner@cactus.org
#
# $Id: Makefile,v 1.6 1996/12/03 04:07:24 asami Exp $
#

PKGNAME=        astrolog-5.30
DISTNAME=       ast53src
EXTRACT_SUFX=   .zip
CATEGORIES=     misc
MASTER_SITES=   http://rpkalf2.mach.uni-karlsruhe.de/~ferber/astrolog/
DISTFILES=      ${EXTRACT_ONLY} ast53dos.zip
EXTRACT_ONLY=   ${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=     ache@FreeBSD.ORG

BUILD_DEPENDS=  unzip:${PORTSDIR}/archivers/unzip

EXTRACT_CMD=    unzip
EXTRACT_ARGS=   -oqLaa
DIST_SUBDIR=    astrolog
MAKEFILE=       makefile.unx
ALL_TARGET=     astrolog
NO_WRKSUBDIR=   Yes

EPHEM=          LRZ5_24 CHI_24 CPJV_24
MISC=           helpfile.530 update.530

post-extract:
	cd ${WRKSRC} && \
		unzip -oq ${DISTDIR}/${DIST_SUBDIR}/ast53dos.zip ${EPHEM}
	cd ${WRKSRC} && \
		unzip -oqLaa ${DISTDIR}/${DIST_SUBDIR}/ast53dos.zip ${MISC}

do-install:
	-@${MKDIR} ${PREFIX}/lib/astrolog
	cd ${WRKSRC} && ${INSTALL_DATA} ${EPHEM} ${PREFIX}/lib/astrolog
	cd ${WRKSRC} && \
		if [ -f ${PREFIX}/lib/astrolog/astrolog.dat ] ; then \
			${INSTALL_DATA} astrolog.dat ${PREFIX}/lib/astrolog/astrolog.dat-dist; \
		else \
			${INSTALL_DATA} astrolog.dat ${PREFIX}/lib/astrolog; \
		fi
	cd ${WRKSRC} && ${INSTALL_PROGRAM} astrolog ${PREFIX}/bin
	-@${MKDIR} ${PREFIX}/share/doc/astrolog
	cd ${WRKSRC} && \
		${INSTALL_DATA} helpfile.530 ${PREFIX}/share/doc/astrolog/Helpfile.530
	cd ${WRKSRC} && \
		${INSTALL_DATA} update.530 ${PREFIX}/share/doc/astrolog/Update.530
	cd ${WRKSRC} && \
		${INSTALL_DATA} readme.530 ${PREFIX}/share/doc/astrolog/Readme.530
	@echo
	@echo "See the file ${PREFIX}/share/doc/astrolog/Helpfile.530 for help"
	@echo "and tune ${PREFIX}/lib/astrolog/astrolog.dat"

.include <bsd.port.mk>
