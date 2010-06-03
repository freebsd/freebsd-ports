# New ports collection makefile for:    astrolog
# See some useful stuff at:
# http://rpkalf2.mach.uni-karlsruhe.de/~ferber/astrolog/
#
# Date created:         31 July 1995
# Whom:                 faulkner@cactus.org
#
# $FreeBSD$
#

PORTNAME=	astrolog
PORTVERSION=	5.40
PORTREVISION=	10
CATEGORIES=	misc
MASTER_SITES=	http://www.astrolog.org/ftp/ephem/:ephem \
		http://www.astrolog.org/ftp/:dist
EXTRACT_ONLY=	ast54unx.shr
EPHEM=		ephemall.zip
DISTFILES=	${EXTRACT_ONLY}:dist ${EPHEM}:ephem

MAINTAINER=	ache@FreeBSD.org
COMMENT=	An astrology program for X11 and alpha-numeric terminals

USE_ZIP=	yes
USE_DOS2UNIX=	ephem/EPHINDEX.TXT
.if !defined(WITHOUT_X11)
USE_XORG=	x11
MAKE_ARGS=	-DX11
.endif
EXTRACT_CMD=	${SH}
EXTRACT_BEFORE_ARGS=	# empty
EXTRACT_AFTER_ARGS=	# empty
DIST_SUBDIR=	astrolog
ALL_TARGET=	astrolog
NO_WRKSUBDIR=	yes

post-extract:
	-@${MKDIR} ${WRKDIR}/ephem
	${UNZIP_CMD} ${EXTRACT_BEFORE_ARGS} ${_DISTDIR}/${EPHEM} -d ${WRKDIR}/ephem

post-patch:
	@${REINPLACE_CMD} -e "s@malloc.h@stdlib.h@g" \
		${WRKSRC}/astrolog.h ${WRKSRC}/placalc.h

do-install:
	-@${MKDIR} ${PREFIX}/lib/astrolog
	cd ${WRKDIR}/ephem && \
		${INSTALL_DATA} * ${PREFIX}/lib/astrolog
	cd ${WRKSRC}; \
		${INSTALL_DATA} astrolog.dat ${PREFIX}/lib/astrolog/astrolog.dat-dist; \
		if [ ! -f ${PREFIX}/lib/astrolog/astrolog.dat ] ; then \
			${INSTALL_DATA} astrolog.dat ${PREFIX}/lib/astrolog; \
		fi
	cd ${WRKSRC} && ${INSTALL_PROGRAM} astrolog ${PREFIX}/bin
	-@${MKDIR} ${PREFIX}/share/doc/astrolog
	cd ${WRKSRC} && \
		${INSTALL_DATA} Helpfile.540 ${PREFIX}/share/doc/astrolog
	cd ${WRKSRC} && \
		${INSTALL_DATA} Update.540 ${PREFIX}/share/doc/astrolog
	cd ${WRKSRC} && \
		${INSTALL_DATA} README.540 ${PREFIX}/share/doc/astrolog
	@${ECHO_MSG}
	@${ECHO_MSG} "See the file ${PREFIX}/share/doc/astrolog/Helpfile.540 for help"
	@${ECHO_MSG} "and tune ${PREFIX}/lib/astrolog/astrolog.dat"

.include <bsd.port.mk>
