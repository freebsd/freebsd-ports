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
PORTREVISION=   1
CATEGORIES=	misc
MASTER_SITES=	http://www.astrolog.org/ftp/ephem/ \
		http://www.astrolog.org/ftp/ \
		ftp://ftp.kiarchive.ru/pub/unix/magick/astrology/astrolog/
EXTRACT_ONLY=	ast54unx.shr
EPHEM=		LRZ5_24 CHI_24 CPJV_24
DISTFILES=	${EXTRACT_ONLY} ${EPHEM}

MAINTAINER=	ache@FreeBSD.org

USE_XLIB=	yes
EXTRACT_CMD=	${SH}
EXTRACT_BEFORE_ARGS=	# empty
EXTRACT_AFTER_ARGS=	# empty
DIST_SUBDIR=	astrolog
ALL_TARGET=	astrolog
NO_WRKSUBDIR=	yes

pre-patch:
	@${PERL} -pi.orig -e "s@malloc.h@stdlib.h@g" \
	${WRKSRC}/astrolog.h ${WRKSRC}/placalc.h

do-install:
	-@${MKDIR} ${PREFIX}/lib/astrolog
	cd ${DISTDIR}/${DIST_SUBDIR} && \
		${INSTALL_DATA} ${EPHEM} ${PREFIX}/lib/astrolog
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
